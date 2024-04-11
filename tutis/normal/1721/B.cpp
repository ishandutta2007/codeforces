/*input
3
2 3 1 3 0
2 3 1 3 1
5 5 3 4 1

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
ll power(ll x, ll y)
{
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	if (y == 0)
		return 1;
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	while (y % 2 == 0)
	{
		y /= 2;
		x = (x * x) % mod;
	}
	ll r = x;
	y /= 2;
	while (true)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		y /= 2;
		if (y == 0)
			break;
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
		int n, m, sx, sy, d;
		cin >> n >> m >> sx >> sy >> d;
		if (sx - 1 > d && (m - sy) > d)
			cout << n + m - 2 << "\n";
		else if (sy - 1 > d && (n - sx) > d)
		{
			cout << n + m - 2 << "\n";
		}
		else
			cout << "-1\n";
	}
	return 0;
}