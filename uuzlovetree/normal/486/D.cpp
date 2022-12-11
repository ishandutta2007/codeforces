#include<bits/stdc++.h>
#define maxn 2005
#define ll long long
using namespace std;
const ll mod = 1000000007;
int n,d;
int a[maxn];
struct edge
{
	int to,next;
}e[maxn<<1];
int head[maxn],p;
void addedge(int u,int v)
{
	e[++p].to=v;e[p].next=head[u];head[u]=p;
}
ll dp[maxn];
void dfs(int u,int f,int minv,int maxv,int rt)
{
	dp[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==f)continue;
		if(a[v]<minv)continue;
		if(a[v]>maxv||(a[v]==maxv&&v<rt))continue;
		dfs(v,u,minv,maxv,rt);
		dp[u]=(dp[u]+dp[u]*dp[v])%mod;
	}
}
int main()
{
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	ll ans=0; 
	for(int u=1;u<=n;++u)
	{
		memset(dp,0,sizeof(dp));
		dfs(u,0,a[u]-d,a[u],u);
		ans+=dp[u];
		ans%=mod;
	}
	printf("%I64d\n",ans);
	return 0;
}