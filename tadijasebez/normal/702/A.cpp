#include <stdio.h>
const int N=100050;
int dp[N],a[N],sol;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]>a[i-1]) dp[i]=dp[i-1]+1;
		else dp[i]=1;
		sol=max(sol,dp[i]);
	}
	printf("%i\n",sol);
	return 0;
}