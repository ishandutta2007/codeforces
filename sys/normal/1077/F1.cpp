#include <bits/stdc++.h>
using namespace std;
const int Maxn=205;
int n,x,k;
long long a[Maxn],dp[Maxn][Maxn]; 
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=min(i,x);j++)
			for(int q=i-1;q>=max(0,i-k);q--)
				dp[i][j]=max(dp[i][j],dp[q][j-1]+a[i]);
	long long ans=-1;
	for(int i=n;i>=n-k+1;i--)
		ans=max(ans,dp[i][x]);
	printf("%lld",ans);
	return 0;
}