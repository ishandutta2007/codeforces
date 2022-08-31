#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
llu F(llu a)
{
	if(a<2)return 0;
	llu x;u i=0,r=0;
	for(x=1;x<=a;x<<=1)++i;
	x>>=1;--i;r=(i*(i-1))>>1;
	for(;x>>=1;++r)if(!(x&a))break;
	a=(a&(x-1))+1;
	if(x&&a==x)++r;
	return r;
}
int main()
{
	llu a,b;
	scanf("%I64u%I64u",&a,&b);
	printf("%I64u\n",F(b)-F(a-1));
	return 0;
}