#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[200005],pa[200005];
ll f[200005],g[200005],h[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	if(!head[node])
	{
		g[node]=1;
		return;
	}
	h[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs(to);
		g[node]=(g[node]*(f[to]+2*g[to]+h[to])+f[node]*(f[to]+g[to]))%MOD;
		f[node]=(f[node]*(g[to]+h[to])+h[node]*(f[to]+g[to]))%MOD;
		h[node]=h[node]*(g[to]+h[to])%MOD;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&pa[i]);
		add(pa[i],i);
	}
	dfs(1);
	printf("%I64d\n",(g[1]+h[1])%MOD);
	return 0;
}