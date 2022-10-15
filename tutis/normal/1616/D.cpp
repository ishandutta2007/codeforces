/*input
4
5
1 2 3 4 5
2
10
2 4 2 4 2 4 2 4 2 4
3
3
-10 -5 -10
-8
3
9 9 -3
5

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll a[n + 1];
		a[0] = -1e8;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ll x;
		cin >> x;
		int dp[n + 1];
		int k[n + 1];
		k[0] = dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			k[i] = 1;
			if (a[i] < x)
			{
				if ((a[i] + a[i - 1]) >= 2 * x)
				{
					k[i] = 2;
					if ((a[i] + a[i - 1] + a[i - 2]) >= 3 * x && (a[i - 1] + a[i - 2]) >= 2 * x)
						k[i] = 2 + k[i - 2];
				}
			}
			else
			{
				if ((a[i] + a[i - 1]) >= 2 * x)
					k[i] = 1 + k[i - 1];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			dp[i] = k[i];
			for (int t = k[i]; t >= k[i] - 5 && t >= 1; t--)
			{
				if (i - t - 1 >= 0)
					dp[i] = max(dp[i], t + dp[i - t - 1]);
				if (i - t - 2 >= 0)
					dp[i] = max(dp[i], t + dp[i - t - 2]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i]);
		cout << ans << "\n";
	}
}