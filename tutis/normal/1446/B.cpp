/*input
4 5
abba
babab

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int dp[n + 1][m + 1];
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 && j == 0)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = -1;
			else
			{
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = max({dp[i - 1][j] - 1, dp[i][j - 1] - 1, dp[i - 1][j - 1] + 2});
					dp[i][j] = max(dp[i][j], 2);
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
				}
				dp[i][j] = max(dp[i][j], -2);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
}