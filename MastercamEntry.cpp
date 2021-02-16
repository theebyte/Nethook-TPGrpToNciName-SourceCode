namespace Nethook
{
	public ref class NethookClass : public Mastercam::App::NetHook3App
	{

	public: virtual Mastercam::App::Types::MCamReturn Run(int param) override
	{
		try
		{
			auto grplist = gcnew System::Collections::Generic::List<Mastercam::Support::Group^>();
			auto ops = Mastercam::Support::SearchManager::GetOperations();
			Mastercam::Support::GroupManager::GetAllGroups(grplist, false);

			for(auto i = 0;i < grplist->Count;i++)
			{
				for(auto k = 0; k < ops->Length; k++)
				{
					ops[k]->SetSelectedState(false);
				}
				for (auto k = 0; k < ops->Length; k++)
				{
					if (grplist[i]->ID == ops[k]->GroupNumber)
					{
						ops[k]->SetSelectedState(true);
					}
				}

				Mastercam::Operations::OperationsManager::SetProgramName(grplist[i]->Name, false);

			}
		}
		catch (System::Exception^ e)
		{
		
		}
		return Mastercam::App::Types::MCamReturn::NoErrors;
	}

	};
}