#include <stdio.h>
const int N=505;
int min(int a, int b){ return a>b?b:a;}
int dp[N][N],vis[N][N],a[N];
int DP(int l, int r)
{
	if(l>r) return 0;
	if(l==r) return 1;
	if(vis[l][r]) return dp[l][r];
	vis[l][r]=1;
	dp[l][r]=DP(l+1,r)+1;
	if(a[l]==a[l+1]) dp[l][r]=min(dp[l][r],DP(l+2,r))+1;
	for(int i=l+2;i<=r;i++) if(a[l]==a[i]) dp[l][r]=min(dp[l][r],DP(l+1,i-1)+DP(i+1,r));
	return dp[l][r];
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	printf("%i\n",DP(1,n));
	return 0;
}