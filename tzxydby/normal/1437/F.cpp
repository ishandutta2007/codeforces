#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int dp[N][N],s[N][N],a[N],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0][0]=s[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int p=upper_bound(a+1,a+n+1,a[i]/2)-a;
		for(int j=1;j<=i;j++)
			dp[i][j]=(dp[i][j]+s[p-1][j-1])%mod;
		for(int j=1;j<=p;j++)
			dp[i][j]=(dp[i][j]+1ll*dp[i][j-1]*(p-j+1)%mod)%mod;
		for(int j=0;j<=i;j++)
			s[i][j]=(s[i-1][j]+dp[i][j])%mod;
	}
	printf("%d\n",dp[n][n]);
	return 0;
}