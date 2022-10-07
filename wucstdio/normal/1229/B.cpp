#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],pa[100005],top[100005];
ll f[100005][50],len[100005][50],v[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	f[node][++top[node]]=v[node];
	len[node][top[node]]=1;
	int x=pa[node];
	for(int i=1;i<=top[x];i++)
	{
		ll d=__gcd(f[node][top[node]],f[x][i]);
		if(d==f[node][top[node]])len[node][top[node]]+=len[x][i];
		else
		{
			f[node][++top[node]]=d;
			len[node][top[node]]=len[x][i];
		}
	}
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=top[i];j++)
		  ans+=f[i][j]*len[i][j]%MOD;
	}
	printf("%lld\n",ans%MOD);
	return 0;
}