#include <bits/stdc++.h>
using namespace std;
const int Maxn=1005,p=998244353;
int n,k,a[Maxn],ans,dp[Maxn][Maxn],sum[Maxn][Maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int x=1;x<=a[n]/(k-1);x++) 
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				dp[i][j]=sum[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][1]=1;
			sum[i][1]=(sum[i-1][1]+1)%p;
			int pnt=upper_bound(a+1,a+1+n,a[i]-x)-a-1;
			for(int j=2;j<=k;j++)
			{
				dp[i][j]=(dp[i][j]+sum[pnt][j-1])%p;
				sum[i][j]=(sum[i-1][j]+dp[i][j])%p;
			}
		}
		for(int i=1;i<=n;i++)
				ans=(ans+dp[i][k])%p;
	}
	printf("%d",ans);
	return 0;
}