/*input
7
5 3
3 8 5 6 7
5 3
3 10 9 8 7
12 8
25 3 3 17 8 6 1 16 15 25 17 23
10 2
1 2 3 4 5 6 7 8 9 10
8 2
2 4 6 8 6 4 12 14
8 2
2 7 8 9 6 13 21 28
15 5
11 4 13 23 7 10 5 21 20 11 17 5 29 16 11

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
	while (true)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		if (y != 0) {
			x = (x * x) % mod;
			y /= 2;
		}
		else
			break;
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
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int i = 0;
		int ans = 0;
		while (i < n)
		{
			int lo = a[i];
			int hi = a[i];
			while (i + 1 < n)
			{
				lo = min(lo, a[i + 1]);
				hi = max(hi, a[i + 1]);
				if (hi - lo > 2 * x)
					break;
				else
					i++;
			}
			i++;
			ans++;
		}
		cout << ans - 1 << "\n";
	}
}