#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		for(int i=0;i<9;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<9;j++)
			{	
				if(s[j]=='1')
				{
					s[j]='2';
					break;
				}
			}
			cout<<s<<"\n";
		}
	}


		

}