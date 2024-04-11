#include <stdio.h>
#define ll long long
const int mod=1e9+7;
int pow(int x, ll p)
{
	int ret=1;
	for(;p;p>>=1,x=(ll)x*x%mod) if(p&1) ret=(ll)ret*x%mod;
	return ret;
}
int main()
{
	ll n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	int sol=pow(2,n-1);
	sol=pow(sol,m-1);
	if(k==-1 && n%2!=m%2) printf("0\n");
	else printf("%i\n",sol);
	return 0;
}