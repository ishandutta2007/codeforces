#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

int n, m, x, res, maxi;
int dp[30003][505];
int T[30003];

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	x=m-250;
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[a]++;
		maxi=max(maxi, a);
	}
	for(int j=0; j<=maxi; j++)
		for(int i=0; i<505; i++)
			dp[j][i]=-1000000000;
	dp[m][250]=T[m];
	for(int i=m; i<=maxi; i++)
	{
		for(int j=max(1, -x+1); j<=500; j++)
		{
			if(dp[i][j]>=0)
			{
				res=max(res, dp[i][j]);
				if(i+j+x<=maxi) dp[i+j+x][j]=max(dp[i+j+x][j], dp[i][j]+T[i+j+x]);
				if(i+j+x+1<=maxi) dp[i+j+x+1][j+1]=max(dp[i+j+x+1][j+1], dp[i][j]+T[i+j+x+1]);
				if(i+j+x-1<=maxi && j+x-1>0) dp[i+j+x-1][j-1]=max(dp[i+j+x-1][j-1], dp[i][j]+T[i+j+x-1]);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}