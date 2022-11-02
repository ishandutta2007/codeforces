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

int n, t;
int dp[105][1005];
vector<PII> V[105];

bool cmp(PII a, PII b)
{
	return a>b;
}

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d%d", &n, &t);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(MP(b, 0));
	}
	for(int i=1; i<=t; i++)
	{
		sort(V[i].begin(), V[i].end(), cmp);
		if(!V[i].empty()) V[i][0].S=V[i][0].F;
		for(int j=1; j<(int)V[i].size(); j++)
			V[i][j].S=V[i][j].F+V[i][j-1].S;
	}
	for(int i=t-1; i>=0; i--)
	{
		for(int j=1; j<=n; j++)
		{
			dp[i][j]=dp[i+1][min(2*j, n)];
			for(int k=1; k<=min((int)V[t-i].size(), j); k++)
			{
				dp[i][j]=max(dp[i][j], V[t-i][k-1].S+dp[i+1][min(2*(j-k), n)]);
			}
		}
	}
	printf("%d\n", dp[0][1]);
	return 0;
}