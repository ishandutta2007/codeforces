#include "bits/stdc++.h"
using namespace std;

int dat[200005];
long long psum[200005];
long long dp[200005];
int n;

// D(t): 0 ~ t     
//  1: t + 1    (psum[t + 1] - D(t + 1))
//  2: D(t+1)
long long D(int t)
{
	if (t == n - 1) return 0;
	if (t == n - 2) return psum[n - 1];

	if (dp[t] == LLONG_MIN)
	{
		dp[t] = max(D(t + 1), psum[t + 1] - D(t + 1));
	}
	return dp[t];
}

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&dat[i]);
		dp[i] = LLONG_MIN;
	}

	psum[0] = dat[0];
	for (int i = 1; i < n; i++) psum[i] = psum[i - 1] + dat[i];

	printf("%lld", D(0));
}