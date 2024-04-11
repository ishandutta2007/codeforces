#include <stdio.h>
#include <vector>
using namespace std;
const int N=2050;
int dp[N][N];
int cnt[N];
int One(int l, int r){ return cnt[r]-cnt[l-1];}
int Two(int l, int r){ return r-l+1-One(l,r);}
int a[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),cnt[i]=cnt[i-1]+(a[i]==1);
	for(i=n;i;i--)
	{
		for(j=i;j;j--)
		{
			if(a[j]==2) dp[j][i]=dp[j+1][i]+1;
			else dp[j][i]=max(dp[j+1][i],One(j,i));
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[j]==2) dp[j][i]=dp[j-1][i]+1;
			else dp[j][i]=max(dp[j-1][i],One(i,j));
		}
	}
	int sol=dp[0][n];
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			int ans=max(One(1,i-1)+dp[i][j]+Two(j+1,n),One(1,j)+dp[n][j+1]);
			ans=max(ans,dp[i-1][1]+Two(i,n));
			sol=max(sol,ans);
		}
	}
	printf("%i\n",sol);
	return 0;
}