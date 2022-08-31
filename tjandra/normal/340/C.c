#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
int F(const void *x,const void *y)
{return((*(u*)x)>=(*(u*)y))+((*(u*)x)>(*(u*)y))-1;}
u a[100000],*A,*B;
llu gcd(llu x,llu y){return y?gcd(y,x%y):x;}
int main()
{
	llu r,R=0,Rr=0;
	u t,x,y,z,i=0;
	for(scanf("%u",&t);i<t;i++)scanf("%u",a+i);
	qsort(a,t,sizeof(u),F);A=a;B=a+t;
	for(r=*A,x=0,i=1;++A<B;i++)
	{
		r+=*A;
		x=*A-*(A-1);
		Rr+=i*(llu)x;
		R+=Rr;
	}
	r+=R<<1;R=gcd(r,t);
	r/=R;t/=R;
	x=r/1000000000u;
	y=r%1000000000u;
	if(x)printf("%u%.9u %u\n",x,y,t);
	else printf("%u %u\n",y,t);
	return 0;
}