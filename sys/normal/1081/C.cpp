#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,k,m,dp[2005][2005];
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	dp[0][0]=m;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];
		dp[0][0]=0;
		for(int j=1;j<=min(k,i);j++)
			dp[i][j]=(dp[i-1][j-1]*(long long)(m-1)+dp[i-1][j])%p;
	}
	printf("%d",dp[n][k]);
	return 0;
}