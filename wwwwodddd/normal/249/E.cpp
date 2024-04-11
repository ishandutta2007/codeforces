#include<stdio.h>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
typedef long double dbl;
int a,b,c,d;
ull p=10000000000ULL;
ull S(ull x)
{
	ull u;
	if(x&1)
		u=(x+1)/2*(2*x+1)%p*x%p;
	else
		u=x/2*(2*x+1)%p*(x+1)%p;
	while(u%3)
		u+=p;
	u/=3;
	return u%p;
}
dbl Q(dbl x)
{
	dbl u=(x+1)*(2*x+1)*x/6;
	return u;
}
ull V(ull x)
{
	if(x&1)
		return (x+1)/2%p*(x%p)%p;
	else
		return x/2%p*(x%p+1)%p;
}
ull G(ull x,ull y)
{
	ull s=min(x,y);
	ull z;
	if(s&1)
		z=(s*s+1)/2%p*s%p*s%p;
	else
		z=(s*s+1)%p*s%p*(s/2)%p;
	if(x<y)
		z=(z+(S(y-1)+p-S(x-1))%p*x%p+(x+1)*x/2%p*(y-x)%p)%p;
	else if(x>y)
		z=(z+(S(x)+p-S(y))%p*y%p+p-(y-1)*y/2%p*(x-y)%p)%p;
	return z;
}
dbl F(dbl x,dbl y)
{
	dbl s=min(x,y);
	dbl z=(s*s+1)*s*s/2;
	if(x<y)
		z=(z+(Q(y-1)-Q(x-1))*x+(x+1)*x/2*(y-x));
	else if(x>y)
		z=(z+(Q(x)-Q(y))*y-(y-1)*y/2*(x-y));
	return z;
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d),a--,b--;
		ull z=p*10+G(c,d)-G(c,b)-G(a,d)+G(a,b);
		dbl zz=F(c,d)-F(c,b)-F(a,d)+F(a,b);
		if(zz<p)
			printf("%I64u\n",z%p);
		else
			printf("...%010I64u\n",z%p);
	}
}