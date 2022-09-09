#include <stdio.h>
#define ll long long
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	ll sol=0;
	for(i=1;i<=k;i++)
	{
		int sz=n-i-i;
		if(sz<0) break;
		sol+=sz*2+1;
	}
	printf("%lld\n",sol);
	return 0;
}