#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int ans=0,las=-1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				if(las==-1)
					las=i;
				else
				{
					ans+=i-las-1;
					las=i;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}