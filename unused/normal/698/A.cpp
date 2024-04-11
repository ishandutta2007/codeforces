#include <stdio.h>
#include <algorithm>
using namespace std;

int dat[1005];

int dp[105][2];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
	}

	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = (dat[1] & 1);
	dp[1][1] = !!(dat[1] & 2);

	int ans = 0;

	for (int i = 2; i <= n; i++)
	{
		if (dat[i] & 1)
		{
			for (int j = 0; j <= i - 2; j++)
			{
				dp[i][0] = max(dp[i][0], dp[j][0]);
			}
			for (int j = 0; j <= i - 1; j++)
			{
				dp[i][0] = max(dp[i][0], dp[j][1]);
			}
			dp[i][0] += 1;
		}
		else dp[i][0] = 0;
		if (dat[i] & 2)
		{
			for (int j = 0; j <= i - 2; j++)
			{
				dp[i][1] = max(dp[i][1], dp[j][1]);
			}
			for (int j = 0; j <= i - 1; j++)
			{
				dp[i][1] = max(dp[i][1], dp[j][0]);
			}
			dp[i][1] += 1;
		}
		else dp[i][1] = 0;
	}

	for (int i = 1; i <= n; i++) ans = max(ans, max(dp[i][0], dp[i][1]));
	printf("%d\n", n - ans);
}