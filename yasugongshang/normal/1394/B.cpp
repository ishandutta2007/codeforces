#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005,K=15;
int n,m,k;
vector<pair<int,int> >G[N];
vector<pair<int,int> >add[N];
int c[K];
bool book[K][K][K][K];
bool check()
{
	for(int i=1;i<=k;i++)
		for(int j=i;j<=k;j++)
			if(book[i][c[i]][j][c[j]]) return false;
	return true;
}
int ans;
void dfs(int s)
{
	if(s==k+1)
	{
		if(check()) ans++;
		return;
	}
	for(int i=1;i<=s;i++)
	{
		c[s]=i;
		dfs(s+1);
	}
	return;
}
bool vis[N][K][K];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back(make_pair(y,z));
	}
	for(int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end(),[](const pair<int,int> &x,const pair<int,int> &y){return x.second<y.second;});
	for(int i=1;i<=k;i++)
		for(c[i]=1;c[i]<=i;c[i]++)
		{
			for(int u=1;u<=n;u++)
				if(G[u].size()==i) 
				{
					int v=G[u][c[i]-1].first;
					if(vis[v][i][c[i]]) book[i][c[i]][i][c[i]]=true;
					else vis[v][i][c[i]]=true,add[v].push_back(make_pair(i,c[i]));
				}
		}
	for(int u=1;u<=n;u++)
		for(unsigned i=0;i<add[u].size();i++)
			for(unsigned j=i+1;j<add[u].size();j++)
			{
				pair<int,int> l=add[u][i],r=add[u][j];
				book[l.first][l.second][r.first][r.second]=true;
			}
	dfs(1);
	printf("%d",ans);
	return 0;
}