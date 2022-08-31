#include<stdio.h>
int main()
{
	long long unsigned n;
	scanf("%I64u",&n);
	while(n%3==0)n/=3;
	printf("%I64u\n",n/3+1);
	return 0;
}