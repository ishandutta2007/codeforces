#include <stdio.h>
#include <math.h>
#define ll long long
const int N=200050;
ll dp[N],sum;
int t[N];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&t[i]),dp[i]=dp[i-1]+t[i];
	for(i=1;i<=n-k+1;i++) sum+=dp[i+k-1]-dp[i-1];
	double ans=(double)sum/(n-k+1);
	printf("%.6Lf\n",ans);
	return 0;
}