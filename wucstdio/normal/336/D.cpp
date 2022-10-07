#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll n,m,g,ans,fact[200005];
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
	return fact[n]*quick_pow(fact[n-m],MOD-2)%MOD*quick_pow(fact[m],MOD-2)%MOD;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&g);
	fact[0]=1;
	for(int i=1;i<=200000;i++)
	  fact[i]=fact[i-1]*i%MOD;
	if(m==0)
	{
		if((n&1)&&g==0||!(n&1)&&g==1)printf("1\n");
		else printf("0\n");
		return 0;
	}
	for(int i=0;i<=n;i+=2)
	  ans=(ans+C(n+m-i-1,m-1))%MOD;
	if(m==1)
	{
		if(n+m&1)ans=(ans-1+MOD)%MOD;
		else ans=(ans+1)%MOD;
	}
	if(g==1)ans=(C(n+m,n)-ans+MOD)%MOD;
	printf("%I64d\n",ans);
	return 0;
}