#include <iostream>
#include <cstdio>
using namespace std;
struct edge
{
	int v,n;
}e[400005];
int head[200005],cnt,vis[200005],deg[200005];
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].n=head[u];
	head[u]=cnt;
}
inline void dfs2(int u,int fa)
{
	if(vis[u])
		return ;
	if(u!=0)
		printf("%d\n",u);
	vis[u]=1;
	for(int i=head[u];i;i=e[i].n)
	{
		if(vis[e[i].v])
			continue;
		if(e[i].v==fa)
			continue;
		dfs2(e[i].v,u);
	}
}
inline void dfs(int u,int fa)
{
	if(vis[u])
		return ;
	for(int i=head[u];i;i=e[i].n)
	{
		if(e[i].v==fa)
			continue;
		dfs(e[i].v,u);
	}
	if(deg[u]&1)
		return ;
	dfs2(u,fa);
	deg[fa]--;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	if(n%2==0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		add(i,v);
		add(v,i);
		if(v==0)
			--deg[i];
		++deg[v],++deg[i];
	}
	dfs(0,0);
	return 0;
}//DLSTXDY!