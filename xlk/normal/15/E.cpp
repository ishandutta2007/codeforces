#include<stdio.h>
long long a=2,b=2,c=4,n,p=1e9+9;
int main()
{
	for(scanf("%I64d",&n);n-=2;)
		a=a*2%p,c=c*(a-3)%p,b=(b+c)%p;
	printf("%I64d",(b*b+1)*2%p);
	return 0;
}