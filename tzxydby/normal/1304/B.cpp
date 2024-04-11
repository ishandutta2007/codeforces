#include<bits/stdc++.h>
using namespace std;
const int N=105;
string s[N],t[N];
int n,m,used[N],p[N];
map<string,vector<int>>mp;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	string ans="";
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=m-1;j>=0;j--)
			t[i]+=s[i][j];
		p[i]=1;
		for(int j=0;j<m;j++)
			if(s[i][j]!=s[i][m-j-1])
				p[i]=0;
		int k=mp[s[i]].size();
		if(k)
		{
			int r=mp[s[i]][k-1];
			used[i]=used[r]=1;
			ans+=s[i];
			mp[s[i]].pop_back();
		}
		else
		{
			mp[t[i]].push_back(i);
		}
	}
	string zh=ans;
	for(int i=1;i<=n;i++)
	{
		if(p[i]&&!used[i])
		{
			zh+=s[i];
			break;
		}
	}
	for(int i=ans.size()-1;i>=0;i--)
		zh+=ans[i];
	cout<<zh.size()<<endl<<zh<<endl;
	return 0;
}