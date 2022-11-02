/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int oo=1000000000;
int dp[120][120][2];
char s[1200];
int n,m,i,j,k;
int main()
{
	while(~scanf("%s",s))
	{
		m=strlen(s);
		scanf("%d",&n);
		for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
		for(k=0;k<2;k++)
		dp[i][j][k]=-oo;
		dp[0][0][0]=dp[0][0][1]=0;
		for(i=0;i<m;i++)
		for(j=0;j<=n;j++)
		{
			if(s[i]=='F')
			{
				for(k=j;k<=n;k+=2)
				{
					dp[i+1][k][0]=max(dp[i+1][k][0],dp[i][j][0]+1);
					dp[i+1][k][1]=max(dp[i+1][k][1],dp[i][j][1]-1);
				}
				for(k=j+1;k<=n;k+=2)
				{
					dp[i+1][k][0]=max(dp[i+1][k][0],dp[i][j][1]);
					dp[i+1][k][1]=max(dp[i+1][k][1],dp[i][j][0]);
				}
			}
			else
			{
				for(k=j;k<=n;k+=2)
				{
					dp[i+1][k][0]=max(dp[i+1][k][0],dp[i][j][1]);
					dp[i+1][k][1]=max(dp[i+1][k][1],dp[i][j][0]);
				}
				for(k=j+1;k<=n;k+=2)
				{
					dp[i+1][k][0]=max(dp[i+1][k][0],dp[i][j][0]+1);
					dp[i+1][k][1]=max(dp[i+1][k][1],dp[i][j][1]-1);
				}
			}
		}
		int ans=max(dp[m][n][0],dp[m][n][1]);
		cout<<ans<<endl;
	}
}