#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
const ll mod = 1000000007;
ll n,m,s,t;
ll fac[maxn],invfac[maxn];
ll fastpow(ll a,ll p)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll A(ll x,ll y)
{
	return fac[x]*invfac[x-y]%mod;
}
ll C(ll x,ll y)
{
	return fac[x]*invfac[y]%mod*invfac[x-y]%mod;
}
ll f(ll x,ll y)
{
	if(x==y)return 1;
	return y*fastpow(x,x-y-1)%mod;
}
int main()
{
	cin>>n>>m>>s>>t;
	fac[0]=1;
	for(int i=1;i<=1000000;++i)fac[i]=fac[i-1]*i%mod;
	for(int i=0;i<=1000000;++i)invfac[i]=fastpow(fac[i],mod-2);
	ll ans=0;
	for(int e=1;e<=n-1;++e)if(m>=e)
	{
		ans+=A(n-2,e-1)*f(n,e+1)%mod*C(m-1,e-1)%mod*fastpow(m,n-e-1)%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
}