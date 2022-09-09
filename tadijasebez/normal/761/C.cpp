#include <stdio.h>
#include <cstring>
const int N=55;
const int inf=1e9+7;
char s[N];
int dp[N][1<<3],val[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,i,j,k;
	scanf("%i %i",&n,&m);
	for(i=0;i<N;i++) for(j=0;j<(1<<3);j++) dp[i][j]=inf;
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
		{
			if(s[j]>='0' && s[j]<='9') val[j]=0;
			else if(s[j]>='a' && s[j]<='z') val[j]=1;
			else val[j]=2;
			for(k=0;k<(1<<3);k++)
			{
				dp[i][k|(1<<val[j])]=min(dp[i][k|(1<<val[j])],dp[i-1][k]+min(j-1,m-j+1));
			}
		}
	}
	printf("%i\n",dp[n][7]);
	return 0;
}