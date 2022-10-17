#include<stdio.h>
long long t,n;
long long pw(long long x,long long y)
{
	long long re=1;
	for(;y;y>>=1)
	{
		if(y&1)
			re=re*x%1000000007;
		x=x*x%1000000007;
	}
	return re;
}
int main()
{
	scanf("%I64d",&n);
	n=pw(2,n);
	printf("%I64d",(n+1)*n/2%1000000007);
}