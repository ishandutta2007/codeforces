#include <stdio.h>
const int N=100050;
int x[N],dp[N],sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x[i]),dp[i]=dp[i-1]+x[i];
	for(i=1;i<n;i++) if(dp[i]==dp[n]-dp[i]) sol++;
	printf("%i\n",sol);
	return 0;
}