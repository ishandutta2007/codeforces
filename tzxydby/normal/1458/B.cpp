#include<bits/stdc++.h>
using namespace std;
const int N=105;
int dp[2][N][N*N],a[N],b[N],n;
void chmax(int &a,int b){if(a<b)a=b;}
int main()
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		int p=i&1,q=p^1;
		memset(dp[p],-1,sizeof(dp[p]));
		for(int j=i;j>=0;j--)
		{
			for(int k=10000;k>=0;k--)
			{
				if(k>=a[i]&&j>=1&&dp[q][j-1][k-a[i]]!=-1)
					chmax(dp[p][j][k],dp[q][j-1][k-a[i]]+b[i]*2);
				if(dp[q][j][k]!=-1)
					chmax(dp[p][j][k],dp[q][j][k]+b[i]);
			}
		}
	}
	int p=n&1;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int k=0;k<=10000;k++)
			mx=max(mx,min(k*2,dp[p][i][k]));
		printf("%.1lf ",0.5*mx);
	}
	return 0;
}