#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int max_n=3e3+5;
int a[max_n];
int dp[max_n][max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		dp[1][1]=0;
		for(int i=2;i<=n;++i)
		{
			for(int j=i;j<=n;++j)
				dp[i][j]=inf;
			int cnt=0;
			for(int j=i-1;j>=1;--j)
			{
				if(j+a[j]>=i)
					dp[i][j+a[j]]=min(dp[i][j+a[j]],dp[j][i-1]+(cnt++));
			}
			for(int j=i+1;j<=n;++j)
				dp[i][j]=min(dp[i][j],dp[i][j-1]);
		}
		printf("%d\n",dp[n][n]);
	}
	return 0;
}