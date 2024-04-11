#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+9;
ll n,m,k,ans,rest;
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
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if(n/k<=n-m)
	{
		printf("%I64d\n",m);
		return 0;
	}
	ans=(n-m)*(k-1)%MOD;
	n-=(n-m)*k;
	rest=n%k;
	n/=k;
	ans=ans+k*quick_pow(2,n+1)%MOD-2*k+MOD;
	ans=(ans+rest)%MOD;
	printf("%I64d\n",(ans+MOD)%MOD);
	return 0;
}