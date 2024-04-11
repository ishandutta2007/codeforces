#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int open=k/2,close=k/2;
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(s[i]=='('&&open>0)
		{
			ans.push_back('(');
			open--;
		}
		if(s[i]==')'&&close>0)
		{
			ans.push_back(')');
			close--;
		}
	}
	cout<<ans<<endl;
}//