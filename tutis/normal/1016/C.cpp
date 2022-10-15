/*input
3
1 2 3
6 5 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n][2];
	for (ll t = 0; t < 2; t++)
		for (ll i = 0; i < n; i++)
			cin >> a[i][t];
	ll dp[n][2];
	dp[n - 1][0] = a[n - 1][1];
	dp[n - 1][1] = a[n - 1][0];
	ll sum[n];
	sum[n - 1] = a[n - 1][0] + a[n - 1][1];
	for (ll i = n - 2; i >= 0; i--)
	{
		dp[i][0] = dp[i + 1][0] + a[i][1] * ((n - 1 - i) * 2 + 1);
		dp[i][1] = dp[i + 1][1] + a[i][0] * ((n - 1 - i) * 2 + 1);
		dp[i][0] += sum[i + 1];
		dp[i][1] += sum[i + 1];
		sum[i] = sum[i + 1] + a[i][0] + a[i][1];
	}
	ll ans = 0;
	ll x = 0;
	ll y = 0;
	ll t = 0;
	ll suma = 0;
	while (x < n)
	{
		suma += t * a[x][y];
		if (x % 2 == 0)
		{
			if (y == 0)
			{
				if (x + 1 < n)
					ans = max(ans, suma + dp[x + 1][y] + sum[x + 1] * (t + 1) + a[x][1] * (2 * n - 1));
				y++;
			}
			else
			{
				if (x + 1 < n)
					ans = max(ans, suma + dp[x + 1][y] + sum[x + 1] * (t + 1));
				x++;
			}
		}
		else
		{
			if (y == 0)
			{
				if (x + 1 < n)
					ans = max(ans, suma + dp[x + 1][y] + sum[x + 1] * (t + 1));
				x++;
			}
			else
			{
				if (x + 1 < n)
					ans = max(ans, suma + dp[x + 1][y] + sum[x + 1] * (t + 1) + a[x][0] * (2 * n - 1));
				y--;
			}
		}
		t++;
	}
	ans = max(ans, suma);
	cout << ans << "\n";
}