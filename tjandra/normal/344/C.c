#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
llu f(llu a,llu b)
{
	if(b==1)return a;
	if(a>b)return a/b+f(b,a%b);
	return f(b,a);
}
int main()
{
	llu a,b;
	scanf("%I64u%I64u",&a,&b);
	printf("%I64u\n",f(a,b));
	return 0;
}