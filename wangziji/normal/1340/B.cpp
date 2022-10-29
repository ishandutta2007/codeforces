#include <iostream>
#include <cstdio>
using namespace std;
int qwq[20][10]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int dp[2005][2005];//dp[i][j]ij 
int w[2005][20];//w[i][j]a[i]j 
int a[2005][20];
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<7;j++)
			scanf("%1d",&a[i][j]);
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<7;k++)
			{
				if(a[i][k]==qwq[j][k]) continue;
				if(a[i][k]==1) w[i][j]=1e9;
				else ++w[i][j];
			}
//			cout << w[i][j] << " ";
		}
//		puts("");
	}
	dp[n+1][0]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=k;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(w[i][k]<=j)
					dp[i][j]|=dp[i+1][j-w[i][k]];
			}
		}
	}
	if(!dp[1][k])
	{
		puts("-1");
		return 0;
	}
	int now=k;
	for(int i=1;i<=n;i++)
	{
		for(int j=9;j>=0;j--)
		{
			if(now>=w[i][j]&&dp[i+1][now-w[i][j]])
			{
				cout << j;now-=w[i][j];
				break;
			}
		}
	}
	return 0;
}