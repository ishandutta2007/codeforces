#include<bits/stdc++.h>
using namespace std;
const int inf = 100000000;
int n,m;
char s[55][55];
int dp[55][2][2][2];
int val[55];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]);
		for(int j=0;j<m;++j)val[j]=min(j,m-j);
	}
	memset(dp,127/2,sizeof(dp));
	dp[0][0][0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<2;++j)
		{
			for(int k=0;k<2;++k)
			{
				for(int l=0;l<2;++l)if(dp[i][j][k][l]<inf)
				{
					for(int p=0;p<m;++p)
					{
						if('0'<=s[i+1][p]&&s[i+1][p]<='9')
							dp[i+1][1][k][l]=min(dp[i+1][1][k][l],dp[i][j][k][l]+val[p]);
						else if('a'<=s[i+1][p]&&s[i+1][p]<='z')
							dp[i+1][j][1][l]=min(dp[i+1][j][1][l],dp[i][j][k][l]+val[p]);
						else dp[i+1][j][k][1]=min(dp[i+1][j][k][1],dp[i][j][k][l]+val[p]);
					}
				}
			}
		}
	}
	printf("%d\n",dp[n][1][1][1]);
	return 0;
}