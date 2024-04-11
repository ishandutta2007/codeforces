#include <stdio.h>
#define ll long long
ll sol,tmp;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	if(n<k*2) k=n-k;
	for(i=1;i<=n;i++)
	{
		sol+=(tmp-1)/n+(tmp+k-1)/n+1;
		tmp+=k;
		printf("%lld ",sol+1);
	}
	return 0;
}