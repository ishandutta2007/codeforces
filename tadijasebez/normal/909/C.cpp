#include <stdio.h>
const int N=5050;
const int mod=1e9+7;
int dp[N][N],sol,n,m,i,j,p; char ch;
int main()
{
	scanf("%i",&n); dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		if(p) for(j=++m;j;j--) dp[i][j]=dp[i-1][j-1];
		else for(j=m;~j;j--) dp[i][j]=(dp[i][j+1]+dp[i-1][j])%mod;
		scanf("\n%c",&ch); p=(ch=='f');
	}
	for(i=0;i<=m;i++) sol=(sol+dp[n][i])%mod;
	printf("%i\n",sol);
	return 0;
}