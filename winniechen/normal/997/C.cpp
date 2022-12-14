#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define N 1000007
#define ll long long
#define mod 998244353
ll q_pow(ll x,ll n)
{
	ll ret=1;
	while(n)
	{
		if(n&1)ret=ret*x%mod;
		x=x*x%mod,n=n>>1;
	}return ret;
}
ll n,ans,C;
int main()
{
	scanf("%lld",&n);
	ans=((q_pow(3,n*n)-q_pow(q_pow(3,n)-3,n))<<1)%mod;C=n;
	for(int i=1;i<=n;i++)
	{
		ll b=q_pow(3,n-i);
		ll ret=(C*(q_pow(b,n)-q_pow(b-1,n))*3)%mod;
		ans+=i&1?-ret:ret;C=C*(n-i)%mod*q_pow(i+1,mod-2)%mod;
	}printf("%lld\n",(ans%mod+mod)%mod);
}