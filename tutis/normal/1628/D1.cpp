/*input
7
3 3 2
2 1 10
6 3 10
6 4 10
100 1 1
4 4 0
69 4 20
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
	ll dp[2002][2002];
	for (int n = 0; n < 2002; n++)
		dp[n][0] = 0;
	for (int m = 0; m < 2002; m++)
		dp[0][m] = m;
	ll i2 = power(2, -1);
	for (int n = 1; n < 2002; n++)
		for (int m = 1; m < 2002; m++)
			dp[n][m] = ((dp[n - 1][m] + dp[n][m - 1]) * i2) % mod;
	while (t--)
	{
		ll n, m, k;
		cin >> n >> m >> k;
		cout << (dp[n - m][m] * k) % mod << "\n";
	}
}