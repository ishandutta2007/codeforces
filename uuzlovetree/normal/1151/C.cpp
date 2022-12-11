#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
ll l,r;
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
ll inv(ll x)
{
	return fastpow(x,mod-2);
}
ll solve(ll n)
{
	if(!n)return 0;
	ll x=1;int L=1;
	while(x*2+1<=n)
	{
		x=x*2+1;
		L++;
	}
	int oddl=(L+1)/2,evenl=L/2;
	ll oddx=0,evenx=0,tx=1,ttx=2;
	for(int i=1;i<=oddl;++i)
	{
		oddx+=tx;
		tx*=4;
	}
	for(int i=1;i<=evenl;++i)
	{
		evenx+=ttx;
		ttx*=4;
	}
	ll ax=oddx%mod,bx=evenx%mod;
	ll res=ax*ax%mod+bx%mod*(1+bx)%mod;
	res%=mod;
	oddx=oddx*2-1;evenx=evenx*2;
	n-=x;
	ll s;
	if(L&1)s=evenx;else s=oddx;
	s%=mod;n%=mod;
	ll t=(n*s%mod+n*(n+1))%mod;
	res=(res+t)%mod;
	return res;
}
int main()
{
	cin>>l>>r;
	ll ans=((solve(r)-solve(l-1))%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}