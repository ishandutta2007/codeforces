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
}e[400005];
int n,m,edgenum,head[200005],dep[200005],pa[200005];
ll f[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	f[node]=1;
	int num=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		f[node]=f[node]*f[to]%MOD;
		num++;
		f[node]=f[node]*num%MOD;
	}
	num++;
	if(node!=1)f[node]=f[node]*num%MOD;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	printf("%I64d\n",f[1]*n%MOD);
	return 0;
}