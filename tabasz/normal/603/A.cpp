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

int n, T[100005];
char C[100005];
int dp[100005][3][2];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%s", &n, C);
	for(int i=1; i<=n; i++)
	{
		if(C[i-1]=='1')
			T[i]=1;
		dp[i][0][0]=dp[i-1][0][0];
		dp[i][0][1]=dp[i-1][0][1];
		dp[i][1][0]=max(dp[i-1][1][0], dp[i-1][0][0]);
		dp[i][1][1]=max(dp[i-1][1][1], dp[i-1][0][1]);
		dp[i][2][0]=max(dp[i-1][1][0], dp[i-1][2][0]);
		dp[i][2][1]=max(dp[i-1][1][1], dp[i-1][2][1]);
		if(T[i]==0)
		{
			dp[i][0][0]=max(dp[i-1][0][0], dp[i-1][0][1]+(int)(T[i]==0));
			dp[i][1][1]=max(max(dp[i-1][1][1], dp[i-1][0][1]), max(dp[i-1][1][0], dp[i-1][0][0])+(int)(T[i]==0));
			dp[i][2][0]=max(max(dp[i-1][1][0], dp[i-1][2][0]), max(dp[i-1][1][1], dp[i-1][2][1])+(int)(T[i]==0));
		}
		if(T[i]==1)
		{
			dp[i][0][1]=max(dp[i-1][0][1], dp[i-1][0][0]+(int)(T[i]==1));
			dp[i][1][0]=max(max(dp[i-1][1][0], dp[i-1][0][0]), max(dp[i-1][1][1], dp[i-1][0][1])+(int)(T[i]==1));	
			dp[i][2][1]=max(max(dp[i-1][1][1], dp[i-1][2][1]), max(dp[i-1][1][0], dp[i-1][2][0])+(int)(T[i]==1));
		}
	}
	printf("%d\n", max(max(dp[n][2][0], dp[n][2][1]), max(dp[n][1][1], dp[n][1][0])));
	return 0;
}