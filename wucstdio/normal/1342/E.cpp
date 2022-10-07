#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,k;
ll ans,fact[200005],inv[200005];
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
int main()
{
	scanf("%d%d",&n,&k);
	if(k>=n)
	{
		printf("0\n");
		return 0;
	}
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%MOD;
	inv[n]=quick_pow(fact[n],MOD-2);
	for(int i=n;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	k=n-k;
	for(int i=0;i<=k;i++)
	{
		if(i&1)ans-=inv[i]*inv[k-i]%MOD*quick_pow(k-i,n)%MOD;
		else ans+=inv[i]*inv[k-i]%MOD*quick_pow(k-i,n)%MOD;
	}
	ans%=MOD;
	for(int i=0;i<k;i++)ans=ans*(n-i)%MOD;
	if(n-k)ans=ans*2%MOD;
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}