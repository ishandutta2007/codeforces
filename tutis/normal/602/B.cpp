/*input
5
1 2 3 3 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int ans = 1;
	int dp[n][3];
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		dp[i][0] = dp[i][1] = dp[i][2] = 1;
		if (i > 0 && a[i - 1] == a[i] + 1)
		{
			dp[i][0] = max(dp[i - 1][2], dp[i - 1][1]) + 1;
		}
		if (i > 0 && a[i - 1] == a[i] - 1)
		{
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + 1;
		}
		if (i > 0 && a[i - 1] == a[i])
		{
			dp[i][2] = dp[i - 1][2] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
			dp[i][0] = dp[i - 1][0] + 1;
		}
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
		ans = max(ans, dp[i][2]);
	}
	cout << ans << "\n";
}