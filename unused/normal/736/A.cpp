#include "bits/stdc++.h"

long long dp[100];

int main()
{
	long long n;
	scanf("%lld", &n);

	if (n == 2) return printf("1"), 0;

	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > n)
		{
			printf("%d", i-1);
			return 0;
		}
	}
}