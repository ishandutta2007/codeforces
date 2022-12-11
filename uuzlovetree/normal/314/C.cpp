#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
const ll mod = 1000000007;
using namespace std;
int n,a[maxn];
ll c[maxn];
void add(int x,ll v)
{
	for(;x<=maxn-5;x+=x&(-x))c[x]=(c[x]+v)%mod;
}
ll query(int x)
{
	ll ans=0;
	for(;x;x-=x&(-x))ans=(ans+c[x])%mod;
	return ans;
}
ll dp[maxn];
bool vis[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		dp[i]=a[i]+query(a[i])*a[i];
		add(a[i],(dp[i]-query(a[i])+query(a[i]-1)+mod)%mod);
	}
	ll ans=0;
	memset(vis,0,sizeof(vis));
	for(int i=n;i;--i)if(!vis[a[i]])ans=(ans+dp[i])%mod,vis[a[i]]=1;
	printf("%I64d\n",ans);
	return 0;
}