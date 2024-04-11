#include <stdio.h>
#define ll long long
int main()
{
	ll a,b,x1,x2,x3;
	scanf("%lld %lld",&a,&b);
	scanf("%lld %lld %lld",&x1,&x2,&x3);
	a-=2*x1;
	a-=x2;
	b-=x2;
	b-=3*x3;
	ll sol=0;
	if(a<0) sol-=a;
	if(b<0) sol-=b;
	printf("%lld\n",sol);
	return 0;
}