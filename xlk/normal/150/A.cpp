#include<stdio.h>
long long n,u;
int main()
{
	scanf("%I64d",&n);
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0&&!u)
			u=i,n/=i;
		if(n%i==0&&n>i)
			return printf("1\n%I64d",u*i),0;
	}
	if(!u)
		puts("1\n0");
	else
		puts("2");
	return 0;
}