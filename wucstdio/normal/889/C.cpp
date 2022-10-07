#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll n,k,f[1000005],fact[1000005],inv[1000005],sum[1000005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
ll C(ll n,ll m)
{
	return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	fact[0]=1;
	for(int i=1;i<=n;i++)
	  fact[i]=fact[i-1]*i%MOD;
	inv[n]=quick_pow(fact[n],MOD-2);
	for(int i=n;i>=1;i--)
	  inv[i-1]=inv[i]*i%MOD;
	f[0]=1;
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=fact[i-1]*(sum[i-1]-(i-k-1<0?0:sum[i-k-1])+MOD)%MOD;
		sum[i]=sum[i-1]+f[i]*inv[i]%MOD;
		if(sum[i]>MOD)sum[i]-=MOD;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	  ans+=f[i-1]*fact[n-1]%MOD*inv[i-1]%MOD;
	ans=fact[n]-ans;
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%I64d\n",ans);
	return 0;
}