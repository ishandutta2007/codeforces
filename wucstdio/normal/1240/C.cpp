#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[1000005];
int n,k,edgenum,head[500005],d[500005],pa[500005];
ll f[500005],g[500005];
ll tmp[500005],top;
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool cmp(ll a,ll b)
{
	return a>b;
}
void dfs(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
	}
	top=0;
	ll sum=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		sum+=max(g[to],f[to]);
		tmp[++top]=max(e[hd].len+f[to]-max(g[to],f[to]),0ll);
	}
	sort(tmp+1,tmp+top+1,cmp);
	if(top<k)
	{
		for(int i=1;i<=top;i++)sum+=tmp[i];
		f[node]=g[node]=sum;
		return;
	}
	for(int i=1;i<k;i++)sum+=tmp[i];
	f[node]=sum,g[node]=sum+tmp[k];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)d[i]=head[i]=pa[i]=0;
		edgenum=0;
		for(int i=1;i<n;i++)
		{
			int u,v,l;
			scanf("%d%d%d",&u,&v,&l);
			add(u,v,l);
			add(v,u,l);
		}
		dfs(1);
		printf("%lld\n",max(f[1],g[1]));
	}
	return 0;
}