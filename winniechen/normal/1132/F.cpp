#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
#define N 505
char s[N];
int dp[N][N];
int main()
{
	scanf("%*d%s",s);
	int n=strlen(s);
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
	}
	for(int l=1;l<n;l++)
	{
		for(int i=1;i+l<=n;i++)
		{
			int j=i+l;
			if(s[i-1]==s[j-1])
			{
				dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
				if(l==1)
				{
					dp[i][j]=1;
				}else
				{
					dp[i][j]=min(dp[i+1][j-1]+1,dp[i][j]);
				}
			}else
			{
				for(int k=i;k<j;k++)
				{
					dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
				}
			}
		}
	}
	printf("%d",dp[1][n]);
	puts("");
}