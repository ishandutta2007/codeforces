#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m;
vector<int> g[maxn],g2[maxn];
int d[maxn];
char Ans[maxn];
bool vis[maxn],vis2[maxn];
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=1;
	for(int v:g[u])dfs(v);
}
void dfs2(int u)
{
	if(vis2[u])return;
	vis2[u]=1;
	for(int v:g2[u])dfs2(v);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g2[v].push_back(u);
		d[v]++; 
	}
	queue<int> q;
	for(int i=1;i<=n;++i)if(!d[i])q.push(i);
	int has=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		++has;
		for(int v:g[u])
		{
			--d[v];
			if(!d[v])q.push(v);
		}
	}
	if(has!=n)puts("-1");
	else
	{
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(vis[i]||vis2[i])Ans[i]='E';
			else Ans[i]='A',++ans;
			dfs(i);
			dfs2(i);
		}
		printf("%d\n",ans);
		printf("%s\n",Ans+1);
	}
}