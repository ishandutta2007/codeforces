/*input
5
4 5
10 10 3 1
1 2
1
3 12
10 10 29
12 51
5 74 89 45 18 69 67 67 11 96 23 59
2 57
85 60

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ll dp[n + 1][31];
		for (int i = 0; i < 31; i++)
			dp[0][i] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int t = 0; t < 30; t++)
			{
				dp[i][t] = dp[i - 1][t] - k + a[i] / (1 << t);
				if (t != 0)
					dp[i][t] = max(dp[i][t], dp[i - 1][t - 1] + a[i] / (1 << t));
			}
			dp[i][30] = max(dp[i - 1][29], dp[i - 1][30]);
		}
		ll ret = 0;
		for (int t = 0; t < 31; t++)
			ret = max(ret, dp[n][t]);
		cout << ret << "\n";
	}
}