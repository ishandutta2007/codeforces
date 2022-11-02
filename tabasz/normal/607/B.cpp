#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n;
int T[505], dp[505][505];

bool pal(int p, int k)
{
	int mid=(p+k)/2;
	for(int i=0; i<=mid-p; i++)
	{
		if(T[i+p]!=T[k-i])
			return false;
	}
	return true;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", T+i);
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j+i<=n; j++)
		{
			dp[j][j+i-1]=1000000;
			if(pal(j, j+i-1))
			{
				dp[j][j+i-1]=1;
				continue;
			}
			if(T[j]==T[j+i-1])
				dp[j][j+i-1]=dp[j+1][j+i-2];
			for(int k=1; k<i; k++)
				dp[j][j+i-1]=min(dp[j][j+i-1], dp[j][j+k-1]+dp[j+k][j+i-1]);
		}
	}
	printf("%d\n", dp[0][n-1]);
	return 0;
}