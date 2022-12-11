#include<bits/stdc++.h>
#define ll long long
#define maxn 400005
using namespace std;
const ll mod = 998244353;
int n,a[maxn];
ll k;
ll fac[maxn],inv[maxn];
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
ll getpow(ll a,ll p)
{
	return fastpow((a%mod+mod)%mod,p);
}
ll C(ll x,ll y)
{
	return fac[x]*inv[x-y]%mod*inv[y]%mod;
}
int main()
{
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=400000;++i)fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=400000;++i)inv[i]=getpow(fac[i],mod-2);
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ll t=0,p=0;
	for(int i=2;i<=n;++i)if(a[i]==a[i-1])t++;else p++;
	if(a[n]==a[1])t++;else p++;
	ll ans=0;
	for(int i=1;i<=p;++i)
	{
		ll res=C(p,i)*getpow(k-4,p-i)%mod*(getpow(2,2*i)%mod-C(2*i,i)+mod)%mod*fastpow(2,mod-2)%mod;
		ans=(ans+res)%mod;
	}
	ans=ans*getpow(k,t)%mod;
	cout<<ans<<endl; 
}