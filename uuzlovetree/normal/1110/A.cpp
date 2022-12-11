#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
const ll mod=2;
ll b,k;
ll a[maxn];
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
int main()
{
	scanf("%I64d%I64d",&b,&k);
	for(int i=1;i<=k;++i)scanf("%I64d",&a[i]);
	ll n=0;
	for(int i=1;i<=k;++i)n=(n+a[i]*fastpow(b,k-i)%mod)%mod;
	if(n)puts("odd");
	else puts("even");
}