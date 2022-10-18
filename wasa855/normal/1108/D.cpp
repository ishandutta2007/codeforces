#include<bits/stdc++.h>
using namespace std;
bool a[205];
int main()
{
	int n;
	string s;
	cin>>n>>s;
	int ans=0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			a[s[i]]=true;
			a[s[i+2]]=true;
			if(a['R']==false)
			{
				s[i+1]='R';
				ans++;
			}
			else if(a['G']==false)
			{
				s[i+1]='G';
				ans++;
			}
			else
			{
				s[i+1]='B';
				ans++;
			}
			a[s[i]]=false;
			a[s[i+2]]=false;
		}
	}
	cout<<ans<<endl;
	cout<<s<<endl;
	return 0;
}