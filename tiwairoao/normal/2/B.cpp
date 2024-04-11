#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int INF=1e9;
ll path[1000+5][1000+5][2];
ll num[1000+5][1000+5][2],dp[1000+5][1000+5][2];
ll a[1000+5][1000+5];
ll n,f=0,x0,y0;//f'0',x0y0'0'
ll Cnt(int x,int k)
{
	ll ret=0;
	while(x%k==0)
	{
		x/=k;
		ret++;
	}
	return ret;
}
void PF(int x,int y,int k)//
{
	if(x==1&&y==1)
		return ;
	if(path[x][y][k]==1)//
	{
		PF(x-1,y,k);
		printf("D");
	}
	else//
	{
		PF(x,y-1,k);
		printf("R");
	}
}
int main()
{
   scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%I64d",&a[i][j]);
			if(a[i][j]==0)
			{
				a[i][j]=10;
				x0=i,y0=j;
				f=1;
			}
			num[i][j][0]=Cnt(a[i][j],2);
			num[i][j][1]=Cnt(a[i][j],5);
		}
	}
	dp[1][1][0]=num[1][1][0];
	dp[1][1][1]=num[1][1][1];
	for(int i=2;i<=n;i++) {
		dp[1][i][0]=dp[1][i-1][0]+num[1][i][0];
		dp[1][i][1]=dp[1][i-1][1]+num[1][i][1];
		path[1][i][0]=path[1][i][1]=0;
		dp[i][1][0]=dp[i-1][1][0]+num[i][1][0];
		dp[i][1][1]=dp[i-1][1][1]+num[i][1][1];
		path[i][1][0]=path[i][1][1]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(i==1||j==1)
				continue;
			if(dp[i][j-1][0]>dp[i-1][j][0])
			{
				dp[i][j][0]=dp[i-1][j][0]+num[i][j][0];
				path[i][j][0]=1;
			}
			else//dp[i][j-1][2]
			{
				dp[i][j][0]=dp[i][j-1][0]+num[i][j][0];// 
				path[i][j][0]=0;
			}
			if(dp[i][j-1][1]>dp[i-1][j][1])
			{
				dp[i][j][1]=dp[i-1][j][1]+num[i][j][1];
				path[i][j][1]=1;
			}
			else//dp[i][j-1][5]
			{
				dp[i][j][1]=dp[i][j-1][1]+num[i][j][1];
				path[i][j][1]=0;
			}
		}
	}
	if(dp[n][n][0]>=1&&dp[n][n][1]>=1&&f)
	{
		printf("1\n");
		for(int i=1;i<x0;i++)
			printf("D");
		for(int i=1;i<n;i++)
			printf("R");
		for(int i=x0+1;i<=n;i++)
			printf("D");
		printf("\n");
	}
	else if(dp[n][n][0]<dp[n][n][1])
	{
		printf("%I64d\n",dp[n][n][0]);
		PF(n,n,0);
		printf("\n");
	}
	else
	{
		printf("%I64d\n",dp[n][n][1]);
		PF(n,n,1);
		printf("\n");
	}
	return 0;
}