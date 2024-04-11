#include <stdio.h>
#define ll long long
ll fir(ll x){ return x*(x-1)/2;}
int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	ll Max=fir(n-m+1);
	ll x=n/m;
	ll cnt1=n%m;
	ll Min=fir(x)*(m-cnt1)+fir(x+1)*cnt1;
	printf("%lld %lld\n",Min,Max);
	return 0;
}