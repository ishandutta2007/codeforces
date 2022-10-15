/*input
723 9

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll dp[1000 + 1][22];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	m *= 2;
	dp[1][0] = 1;
	ll ans = 0;
	for (ll i = 1; i <= m; i++)
	{
		ll sum = 0;
		for (ll x = 1; x <= n; x++)
		{
			sum += dp[x][i - 1];
			if (sum >= mod)
				sum -= mod;
			dp[x][i] = sum;
		}
	}
	for (ll x = 1; x <= n; x++)
	{
		ans += dp[x][m];
		if (ans >= mod)
			ans -= mod;
	}
	cout << ans << "\n";
}