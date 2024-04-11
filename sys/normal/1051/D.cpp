#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
long long dp[1005][2005][7],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	dp[1][1][0]=dp[1][2][1]=dp[1][2][2]=dp[1][1][3]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=2*n;j++)
		{
			if(j==1)
			{
				dp[i][j][1]=dp[i-1][j][1];
				dp[i][j][2]=dp[i-1][j][2];
				dp[i][j][3]=dp[i-1][j][3];
				dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%p;
			}
			else if(j==2)
			{
				dp[i][j][1]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-1][3])%p;
				dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j][2]+dp[i-1][j-1][3])%p;
				dp[i][j][3]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%p;
				dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%p;
			}
			else
			{
				dp[i][j][1]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-2][2]+dp[i-1][j-1][3])%p;
				dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j-2][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%p;
				dp[i][j][3]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%p;
				dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%p;
			}
		}
	printf("%d",(dp[n][m][0]+dp[n][m][1]+dp[n][m][2]+dp[n][m][3])%p);
	return 0;
}