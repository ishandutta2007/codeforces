#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[101][101][101][2];
int p[101];
int main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)p[i]=read();
	dp[0][0][0][1]=dp[0][0][0][0]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[0][i][j][1]=dp[0][i][j][0]=100000000;
	for(int i=1;i<=n;i++)
	{
		if(p[i]!=0)
		{
			if(p[i]%2==0)
			{
				for(int j=0;j<=n;j++)
				{
					for(int k=0;k<=n;k++)
					{
						dp[i][j][k][1]=1000000000;
						if(j!=0)dp[i][j][k][0]=min(dp[i-1][j-1][k][0],dp[i-1][j-1][k][1]+1);
						else dp[i][j][k][0]=1000000000;
					}
				}
			}
			else
			{
				for(int j=0;j<=n;j++)
				{
					for(int k=0;k<=n;k++)
					{
						dp[i][j][k][0]=1000000000;
						if(k!=0)dp[i][j][k][1]=min(dp[i-1][j][k-1][1],dp[i-1][j][k-1][0]+1);
						else dp[i][j][k][1]=1000000000;
					}
				}
			}
		}
		else
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					if(k!=0)dp[i][j][k][1]=min(dp[i-1][j][k-1][1],dp[i-1][j][k-1][0]+1);
					else dp[i][j][k][1]=1000000000;
					if(j!=0)dp[i][j][k][0]=min(dp[i-1][j-1][k][0],dp[i-1][j-1][k][1]+1);
					else dp[i][j][k][0]=1000000000;
				}
			}
		}
	}
	printf("%d\n",min(dp[n][n/2][n-n/2][0],dp[n][n/2][n-n/2][1]));
	return 0;
}