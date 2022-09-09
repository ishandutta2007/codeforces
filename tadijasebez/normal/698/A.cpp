#include <stdio.h>
const int N=105;
const int inf=1000000000;
int dp[N][3];
int min(int a, int b){ return a>b?b:a;}
int min(int a, int b, int c){ return min(a,min(b,c));}
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x==0)
		{
			dp[i][0]=min(dp[i-1][0],dp[i-1][1],dp[i-1][2])+1;
			dp[i][1]=inf;
			dp[i][2]=inf;
		}
		if(x==1)
		{
			dp[i][0]=min(dp[i-1][0],dp[i-1][1],dp[i-1][2])+1;
			dp[i][1]=inf;
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
		if(x==2)
		{
			dp[i][0]=min(dp[i-1][0],dp[i-1][1],dp[i-1][2])+1;
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=inf;
		}
		if(x==3)
		{
			dp[i][0]=min(dp[i-1][0],dp[i-1][1],dp[i-1][2])+1;
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
	}
	printf("%i\n",min(dp[n][0],dp[n][1],dp[n][2]));
	return 0;
}