#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

int T[100005], res=0;
int dp[3][100005];
int dp2[3][100005];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", T+i);
	dp[0][0]=1;
	dp[1][0]=1;
	dp[2][0]=1;
	for(int i=1; i<n; i++)
	{
		dp[1][i]=dp[0][i-1]+1;
		dp[0][i]=1;
		dp[2][i]=1;
		if(T[i]>T[i-1]) dp[0][i]=dp[0][i-1]+1;
		if(T[i]>T[i-1]) dp[2][i]=dp[2][i-1]+1;
		if(i>1 && T[i]>max(T[i-1], T[i-2]+1))  dp[2][i]=max(dp[2][i], max(dp[0][i], dp[1][i-1]+1));
	}
	dp2[0][n-1]=1;
	dp2[1][n-1]=1;
	dp2[2][n-1]=1;
	for(int i=n-2; i>=0; i--)
	{
		dp2[1][i]=dp2[0][i+1]+1;
		dp2[0][i]=1;
		dp2[2][i]=1;
		if(T[i]<T[i+1]) dp2[0][i]=dp2[0][i+1]+1;
		if(T[i]<T[i+1]) dp2[2][i]=dp2[2][i+1]+1;
		if(i<n-2 && T[i]<min(T[i+1], T[i+2]-1))  dp2[2][i]=max(dp2[2][i], max(dp2[0][i], dp2[1][i+1]+1));
	}
	for(int i=0; i<n; i++)
	{
		//printf("%d %d %d\n", dp[0][i], dp[1][i], dp[2][i]);
		res=max(max(res, dp[2][i]), max(dp[0][i], dp[1][i]));
		res=max(max(res, dp2[2][i]), max(dp2[0][i], dp2[1][i]));
	}
	printf("%d\n", res);
	return 0;
}