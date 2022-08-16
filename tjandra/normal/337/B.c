#include<stdio.h>
typedef unsigned u;
u gcd(a,b){u r;while(b){r=a%b;a=b;b=r;};return a;}
int main()
{
	u a,b,c,d,p,q,r;
	scanf("%u%u%u%u",&a,&b,&c,&d);
	a*=d;b*=c;
	if(a>b){p=a-b;q=a;}
	else{p=b-a;q=b;}
	r=gcd(p,q);
	p/=r;q/=r;
	printf("%u/%u\n",p,q);
	return 0;
}