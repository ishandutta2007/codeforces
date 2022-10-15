/*input
2
2 2 4
0 1000000
0 1000000
1 0
1000000 1
999999 1000000
0 999999
5 4 9
0 1 2 6 1000000
0 4 8 1000000
4 4
2 5
2 2
6 3
1000000 1
3 8
5 8
8 8
6 8
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
ll F[200009];
int main()
{
	F[0] = 1;
	for (int i = 1; i < 200009; i++)
		F[i] = (F[i - 1] * i) % mod;
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int x[n];
		for (int i = 0; i < n; i++)
			cin >> x[i];
		int y[m];
		for (int i = 0; i < m; i++)
			cin >> y[i];
		ll ans = 0;
		map<int, int>X, Y;
		map<pair<int, int>, int>A;
		map<pair<int, int>, int>B;
		while (k--)
		{
			int a, b;
			cin >> a >> b;
			if (binary_search(x, x + n, a))
			{
				if (binary_search(y, y + m, b))
					continue;
				int i = lower_bound(y, y + m, b) - y;
				ans += Y[i]++;
				int c = lower_bound(x, x + n, a) - x;
				ans -= A[ {c, i}]++;
			}
			else
			{
				int j = lower_bound(x, x + n, a) - x;
				int i = lower_bound(y, y + m, b) - y;
				ans += X[j]++;
				ans -= B[ {i, j}]++;
			}
		}
		cout << ans << "\n";
	}
}