#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m,s,t;
int a[maxn],b[maxn];
vector<int> g[maxn*2];
bool vis[maxn*2];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<g[u].size();++i)
	{
		int v=g[u][i];
		if(vis[v])continue;
		dfs(v);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	s=0;t=n*2+1;
	if(a[1])g[0].push_back(1);
	if(b[1])g[0].push_back(n+1);
	if(a[m])g[m].push_back(t);
	if(b[m])g[m+n].push_back(t);
	for(int i=1;i<n;++i)g[i].push_back(i+1);
	for(int i=n;i>1;--i)g[i+n].push_back(i-1+n);
	for(int i=1;i<=n;++i)if(a[i]&&b[i])g[i].push_back(i+n),g[i+n].push_back(i);
	dfs(s);
	if(vis[t])puts("YES");
	else puts("NO");
	return 0;
}