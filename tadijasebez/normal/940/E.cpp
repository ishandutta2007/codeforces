#include <stdio.h>
const int N=100050;
int a[N],l,r=-1,q[N];
#define ll long long
ll dp[N],b[N];
int main()
{
	int n,c,i;
	scanf("%i %i",&n,&c); 
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);b[i]=b[i-1]+a[i];
		while(l<=r && q[l]<=i-c) l++;
		while(l<=r && a[q[r]]>=a[i]) r--;
		q[++r]=i;
		dp[i]=dp[i-1]+a[i];
		if(i>=c && dp[i]>dp[i-c]+b[i]-b[i-c]-a[q[l]]) dp[i]=dp[i-c]+b[i]-b[i-c]-a[q[l]];
	}
	printf("%lld\n",dp[n]);
	return 0;
}