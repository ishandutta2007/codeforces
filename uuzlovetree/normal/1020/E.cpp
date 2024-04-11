#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,m;
vector<int> g[maxn],gg[maxn];
bool vis[maxn],used[maxn];
int ans[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int u,v,i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		gg[v].push_back(u);
	}
	for(int u=1;u<=n;++u)if(!vis[u])
	{
		used[u]=1;
		for(int j=0;j<g[u].size();++j)vis[g[u][j]]=1;
	}
	int cnt=0;
	for(int u=n;u;--u)if(used[u])
	{
		ans[++cnt]=u;
		for(int j=0;j<g[u].size();++j)used[g[u][j]]=0;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)printf("%d ",ans[i]);
	return 0;
}