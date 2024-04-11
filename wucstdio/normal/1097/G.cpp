#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
struct Edge
{
	int to;
	int next;
}e[200005];
int n,k,edgenum,head[100005],pa[100005],size[100005];
ll f[100005][205],s[205][205],tmp[205],sum[205];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	f[node][0]=2;
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<=min(k,size[node]);i++)
		  for(int j=0;j<=min(k-i,size[to]);j++)
		    tmp[i+j]+=f[node][i]*f[to][j]%MOD;
		size[node]+=size[to];
		for(int i=0;i<=min(k,size[node]);i++)
		  f[node][i]=tmp[i]%MOD;
		for(int i=0;i<=min(k,size[node]);i++)
		  sum[i]-=f[to][i];
	}
	for(int i=0;i<=min(k,size[node]);i++)
	  sum[i]+=f[node][i];
	for(int i=k;i>0;i--)
	  f[node][i]+=f[node][i-1];
	f[node][1]--;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	s[0][0]=1;
	for(int i=1;i<=k;i++)
	  for(int j=1;j<=k;j++)
	    s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%MOD;
	dfs(1);
	ll fact=1;
	ll ans=0;
	for(int i=0;i<=k;i++)
	{
		sum[i]%=MOD;
		if(sum[i]<0)sum[i]+=MOD;
	}
	for(int i=1;i<=k;i++)
	{
		fact=fact*i%MOD;
		ans+=fact*s[k][i]%MOD*sum[i]%MOD;
	}
	printf("%I64d\n",ans%MOD);
	return 0;
}