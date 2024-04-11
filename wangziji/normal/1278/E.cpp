#include <iostream>
#include <cstdio>
using namespace std;
pair <int,int> ans[1000005];
int fa[1000005],sz[1000005],head[1000005],cnt,used[1000005],p[1000005],siz[1000005];
struct edge
{
	int v,n;
}e[2000005];
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].n=head[u];
	head[u]=cnt;
}
inline void dfs2(int u,int l,int r)
{
	//cout << u << " " << l << " " << r << endl;
	int sum=0,nowr=l;
	for(int i=head[u];i;i=e[i].n)
	{
		if(e[i].v==fa[u])
			continue;
		ans[e[i].v]={nowr-sz[e[i].v]-1-sum,nowr};
		sum+=siz[e[i].v]*2;
		++nowr;
		dfs2(e[i].v,ans[e[i].v].first+1,ans[e[i].v].second-1);
	}
}
inline void dfs(int u,int f)
{
	fa[u]=f;
	p[++cnt]=u;
	for(int i=head[u];i;i=e[i].n)
	{
		if(e[i].v==fa[u])
			continue;
		++sz[u];
		dfs(e[i].v,u);
		siz[u]+=siz[e[i].v];
	}
	++siz[u];
	if(fa[u]) ++sz[u];
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=2;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	cnt=0;
	dfs(1,0);
	ans[1]={n*2-sz[1]-1,n*2};
	dfs2(1,ans[1].first+1,ans[1].second-1); 
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}