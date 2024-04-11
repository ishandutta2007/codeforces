/*input
3
6 3
0 0 2 5 1 1
2 3
0 2
3 2
3 0 2

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
mt19937_64 rng(123);
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
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int lo[n], hi[n];
		for (int i = 0; i < n; i++)
		{
			cin >> lo[i];
			hi[i] = lo[i] + k - 1;
		}
		hi[0] = lo[0];
		hi[n - 1] = lo[n - 1];
		bool ok = true;
		for (int i = 1; i <= n - 2; i++)
		{
			hi[i] = min(hi[i], min(hi[i - 1], hi[i + 1]) + k - 1);
			lo[i] = max(lo[i], max(lo[i - 1], lo[i + 1]) - k + 1);
			if (hi[i] < lo[i])
				ok = false;
		}
		for (int i = n - 2; i >= 1; i--)
		{
			hi[i] = min(hi[i], min(hi[i - 1], hi[i + 1]) + k - 1);
			lo[i] = max(lo[i], max(lo[i - 1], lo[i + 1]) - k + 1);
			if (hi[i] < lo[i])
				ok = false;
		}
		if (n == 2)
			if (abs(lo[0] - lo[1]) >= k)
				ok = false;
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

}