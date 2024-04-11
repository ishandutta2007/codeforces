/*input
3
3
2 4
2 1
3 5
3
2 3
2 10
2 6
4
1 7
3 3
2 6
1000000000 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		ll a[n], b[n];
		for (ll i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		ll dp[n][3];
		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = 2 * b[0];
		for (ll i = 1; i < n; i++)
		{
			for (ll x = 0; x < 3; x++)
			{
				dp[i][x] = 2e18;
				for (ll y = 0; y < 3; y++)
				{
					if (a[i] + x != a[i - 1] + y)
					{
						dp[i][x] = min(dp[i][x], dp[i - 1][y] + x * b[i]);
					}
				}
			}
		}
		cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";
	}
}