#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,m;
char s[maxn][maxn];
int dp[maxn][2];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]);
	int minv=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)if(s[i][j]!='0')goto L;
		minv=i+1;
	}
	L:;
	memset(dp,127/2,sizeof(dp));
	dp[n][0]=0;
	for(int i=n;i>=minv;--i)
	{
		int maxp=0,minp=m+1;
		for(int j=1;j<=m;++j)if(s[i][j]=='1')maxp=max(maxp,j),minp=min(minp,j);
		if(i>minv) 
		{
			if(maxp==0&&minp==m+1)
			{
				dp[i-1][0]=min(dp[i][0]+1,dp[i][1]+m+2);
				dp[i-1][1]=min(dp[i][1]+1,dp[i][0]+m+2);
			}
			else
			{
				dp[i-1][0]=min(dp[i][0]+2*maxp+1,dp[i][1]+m+2);
				dp[i-1][1]=min(dp[i][1]+2*(m+1-minp)+1,dp[i][0]+m+2);
			}
		}
		else
		{
			dp[i-1][0]=min(dp[i][0]+maxp,dp[i][1]+m+1);
			dp[i-1][1]=min(dp[i][1]+m+1-minp,dp[i][0]+m+1);
		}
	}
	printf("%d\n",min(dp[minv-1][0],dp[minv-1][1]));
	return 0;
}