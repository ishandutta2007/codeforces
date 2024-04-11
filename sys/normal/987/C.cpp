#include <bits/stdc++.h>
using namespace std;
int dp[3005][6],minn=0x7fffffff,n,siz[3005],val[3005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&siz[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
		dp[i][1]=val[i];
		dp[i][2]=0x3f3f3f3f;
		dp[i][3]=0x3f3f3f3f;
	}
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
		{
			if(siz[i]<siz[j])
			{
				dp[i][2]=min(dp[i][2],dp[j][1]+val[i]);
				dp[i][3]=min(dp[i][3],dp[j][2]+val[i]);
			}
		}
	for(int i=1;i<=n-2;i++)
		minn=min(dp[i][3],minn);
	printf("%d",minn==0x3f3f3f3f?-1:minn);
	return 0;
}