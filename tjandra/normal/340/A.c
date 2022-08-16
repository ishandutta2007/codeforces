#include<stdio.h>
typedef unsigned u;
u gcd(u a,u b){return b?gcd(b,a%b):a;}
int main()
{
	u x,y,z,a,b;
	scanf("%u%u%u%u",&x,&y,&a,&b);
	z=x*y/gcd(x,y);
	printf("%u\n",b/z-(--a)/z);
	return 0;
}