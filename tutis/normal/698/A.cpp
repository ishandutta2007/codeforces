/*input
10
0 0 1 1 0 0 0 0 1 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[2][500 + 1][500 + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int dp[n + 1][3];
	dp[0][1] = 0;
	dp[0][0] = 0;
	dp[0][2] = 0;
	int ans = n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		dp[i][2] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
		for (int t = 0; t < 2; t++)
		{
			dp[i][t] = 100000;
			if (((1 << t) & (a)) > 0)
			{
				if (t == 0)
				{
					if (i - 2 >= 0)
					{
						dp[i][0] = min(dp[i][0], dp[i - 2][0] + 1);
						dp[i][0] = min(dp[i][0], dp[i - 2][1] + 1);
					}
					dp[i][0] = min(dp[i][0], dp[i - 1][1]);
					dp[i][0] = min(dp[i][0], dp[i - 1][2]);
				}
				if (t == 1)
				{
					if (i - 2 >= 0)
					{
						dp[i][1] = min(dp[i][1], dp[i - 2][0] + 1);
						dp[i][1] = min(dp[i][1], dp[i - 2][1] + 1);
					}
					dp[i][1] = min(dp[i][1], dp[i - 1][0]);
					dp[i][1] = min(dp[i][1], dp[i - 1][2]);
				}
			}
			ans = min(ans, dp[i][t] + n - i);
		}
	}
	cout << ans << "\n";
}