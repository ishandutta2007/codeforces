/*input
5
200000000 100000000 1
600000000 400000000 0
800000000 300000000 0
900000000 700000000 1
1000000000 500000000 0

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
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 998244353;
//const ll mod = 1000000007;
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
	int n;
	cin >> n;
	ll x[n + 1], y[n + 1], s[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i] >> s[i];
	x[0] = y[0] = 0;
	ll dpa[n + 1];
	ll dpas[n + 1];
	ll dp[n + 1];
	dp[0] = 0;
	dpa[0] = 0;
	dpas[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dpa[i] = x[i] - y[i];
		dpa[i] %= mod;
		if (x[i - 1] > y[i])
		{
			int lo = 0;
			int hi = i - 1;
			while (lo < hi)
			{
				int id = (lo + hi + 1) / 2;
				if (x[id] > y[i])
					hi = id - 1;
				else
					lo = id;
			}
			dpa[i] += dpas[i - 1] - dpas[lo];
		}
		dpa[i] %= mod;
		if (dpa[i] < 0)
			dpa[i] += mod;


		dp[i] = dp[i - 1] + (x[i] - x[i - 1]);
		if (s[i] == 1)
			dp[i] += dpa[i];
		dp[i] %= mod;


		dpas[i] = dpas[i - 1] + dpa[i];
		dpas[i] %= mod;
	}
	cout << (dp[n] + 1) % mod << "\n";
}