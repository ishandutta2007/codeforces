#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353,inv2=499122177;
int n,k,a[200005];
ll kk,ans,fact[200005],inv[200005];
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
ll C(int n,int m)
{
	return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int nn=n;
	kk=1;
	for(int i=1;i<=n;i++)
	  if(a[i]==a[i%n+1])
	    nn--,kk=kk*k%MOD;
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%MOD;
	inv[n]=quick_pow(fact[n],MOD-2);
	for(int i=n;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	n=nn;
	for(int i=0;i<=n;i++)
	{
		ans=(ans+quick_pow(k-2,i)*C(n,i)%MOD*inv2%MOD*((n-i)%2==0?quick_pow(2,n-i)-C(n-i,(n-i)/2)+MOD:quick_pow(2,n-i)))%MOD;
	}
	printf("%lld\n",ans*kk%MOD);
	return 0;
}