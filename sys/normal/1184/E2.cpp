#include <bits/stdc++.h>
using namespace std;
const int Maxn=1000005;
int dep[Maxn],maxi[Maxn][23],anc[Maxn][23],cnt,head[Maxn],n,m,fa[Maxn];
bool choose[Maxn];
int get_fa(int x)
{
	return x==fa[x]?x:fa[x]=get_fa(fa[x]);
}
void merge(int x,int y)
{
	int a=get_fa(x),b=get_fa(y);
	fa[a]=b;
}
struct Edg
{
	int x,y,w,id;
	bool operator < (const Edg &tmp) const
	{
		return w<tmp.w;
	}
}Edge[Maxn];
struct edg
{
	int nxt,to,w;
}edge[Maxn];
void add(int x,int y,int w)
{
	edge[++cnt]=(edg){head[x],y,w};
	head[x]=cnt;
}
void kruskal(void)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(Edge+1,Edge+1+m);
	for(int i=1;i<=m;i++)
	{
		int x=Edge[i].x,y=Edge[i].y;
		if(get_fa(x)!=get_fa(y))
		{
			merge(x,y);
			choose[i]=true;
			add(x,y,Edge[i].w);
			add(y,x,Edge[i].w);
		}
	}
}
void dfs(int u,int fa)
{
	anc[u][0]=fa;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			maxi[to][0]=edge[i].w;
			dep[to]=dep[u]+1;
			dfs(to,u);
		}
	}
}
void init(void)
{
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j<=n;j++)
		{
			anc[j][i]=anc[anc[j][i-1]][i-1];
			maxi[j][i]=max(maxi[j][i-1],maxi[anc[j][i-1]][i-1]);
		}
}
int lca(int x,int y)
{
	int ans=0;
	if(dep[x]<dep[y]) swap(x,y);
	int diff=dep[x]-dep[y];
	for(int i=log2(n);i>=0;i--)
		if(diff&(1<<i)) ans=max(ans,maxi[x][i]),x=anc[x][i];
	if(x==y) return ans;
	for(int i=log2(n);i>=0;i--)
	{
		if(anc[x][i]!=anc[y][i])
		{
			ans=max(ans,max(maxi[x][i],maxi[y][i]));
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return max(ans,max(maxi[x][0],maxi[y][0]));
}
int ans[Maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&Edge[i].x,&Edge[i].y,&Edge[i].w),Edge[i].id=i;
	kruskal();
	dfs(1,0);
	init();
	for(int i=1;i<=m;i++)
		if(!choose[i])
			ans[Edge[i].id]=lca(Edge[i].x,Edge[i].y);
	for(int i=1;i<=m;i++)
		if(ans[i]) printf("%d\n",ans[i]);
	return 0;
}