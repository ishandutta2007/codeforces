#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int Solve(ll n)
{
	ll odd=0,even=0;
	ll s=0,i,j=1;
	for(i=1;s<n;i*=2)
	{
		ll add=min(n-s,i);
		s+=add;
		if(j==1) odd+=add;
		else even+=add;
		j^=1;
	}
	odd%=mod;
	even%=mod;
	ll ans=odd*odd+even*even+even;
	return ans%mod;
}
int main()
{
	ll l,r;
	scanf("%lld %lld",&l,&r);
	printf("%i\n",(Solve(r)-Solve(l-1)+mod)%mod);
	return 0;
}