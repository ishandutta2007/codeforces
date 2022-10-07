#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
	ll len;
}e[400005];
int t,n,m,edgenum,head[200005],pa[200005],size[200005];
ll v1,v2;
void add(int u,int v,ll l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
		v1+=min(size[to],n-size[to])*e[hd].len;
		v2+=(size[to]&1)*e[hd].len;
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n=n*2;
		edgenum=0;
		v1=v2=0;
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			ll l;
			scanf("%d%d%lld",&u,&v,&l);
			add(u,v,l);
			add(v,u,l);
		}
		dfs(1);
		printf("%lld %lld\n",v2,v1);
	}
	return 0;
}