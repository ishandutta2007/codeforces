#include<bits/stdc++.h>
using namespace std;
const int N=105;
int ans[N][N][30];
vector<pair<int,int>>e[N];
int dfs(int a,int b,int c)
{
	if(ans[a][b][c]!=-1)
		return ans[a][b][c];
	ans[a][b][c]=0;
	for(int i=0;i<e[a].size();i++)
	{
		int v=e[a][i].first;
		if(e[a][i].second<c)
			continue;
		if(!dfs(b,e[a][i].first,e[a][i].second))
		{
			ans[a][b][c]=1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(ans,-1,sizeof(ans));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		char c;
		cin>>u>>v>>c;
		e[u].push_back(make_pair(v,c-'a'));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dfs(i,j,0))
				cout<<'A';
			else
				cout<<'B';
		}
		cout<<endl;
	}
	return 0;
}