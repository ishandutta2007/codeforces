#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int hav[Maxn],n,m,k,head[Maxn],cnt,fa[Maxn],ans,dp[Maxn];
bool spec[Maxn];
struct edg
{
	int x,y,w;
	bool operator < (const edg &tmp) const
	{
		return w<tmp.w;
	}
}edges[Maxn];
struct ed
{
	int nxt,to,w;
}edge[2*Maxn];
void add(int x,int y,int w)
{
	edge[++cnt]=(ed){head[x],y,w};
	head[x]=cnt;
}
int get_fa(int x)
{
	return x==fa[x]?x:fa[x]=get_fa(fa[x]);
}
void merge(int x,int y)
{
	int a=get_fa(x),b=get_fa(y);
	fa[a]=b;
}
void kruskal(void)
{
	int done=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(edges+1,edges+1+m);
	for(int i=1;i<=m;i++)
	{
		int x=edges[i].x,y=edges[i].y,w=edges[i].w;
		if(get_fa(x)!=get_fa(y))
		{
			merge(x,y);
			add(x,y,w);
add(y,x,w);
			done++;
		}
		if(done==n-1) return ;
	}
}
void dfs(int u,int fa)
{
	if(spec[u]) hav[u]=true;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to,w=edge[i].w;
		if(to!=fa)
		{
			dfs(to,u);
			if(hav[to])
				dp[u]=max(dp[u],max(dp[to],edge[i].w));
			hav[u]+=(bool)hav[to];
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		spec[x]=true;
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].w);
	kruskal();
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(hav[i]>=2) ans=max(ans,dp[i]);
	for(int i=1;i<=k;i++)
		printf("%d ",ans);
	return 0;
}