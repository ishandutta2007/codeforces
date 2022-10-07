#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[1000005];
int t,n,m,edgenum,a,b,head[200005],pa[200005],size[200005];
bool flag[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	flag[node]=1;
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		if(flag[to])continue;
		if(to==a||to==b)continue;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		edgenum=0;
		for(int i=1;i<=n;i++)head[i]=pa[i]=flag[i]=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(a);
		long long ans=n-size[a]-1;
		for(int i=1;i<=n;i++)pa[i]=flag[i]=0;
		dfs(b);
		ans*=n-size[b]-1;
		printf("%lld\n",ans);
	}
	return 0;
}