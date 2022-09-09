#include <stdio.h>
#define ll long long
const int N=200050;
ll x[N],dp[N];
int t[N];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&t[i]),dp[i]=dp[i-1]+t[i];
	for(i=1;i<=n-k+1;i++) x[i]=dp[i+k-1]-dp[i-1];
	ll best=0,sol=0;
	int naj,first,second;
	for(i=k+1;i<=n;i++)
	{
		if(best<x[i-k])
		{
			best=x[i-k];
			naj=i-k;
		}
		if(sol<best+x[i])
		{
			sol=best+x[i];
			first=naj;
			second=i;
		}
	}
	printf("%i %i\n",first,second);
	return 0;
}