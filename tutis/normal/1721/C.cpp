/*input
4
3
2 3 5
7 11 13
1
1000
5000
4
1 2 3 4
1 2 3 4
4
10 20 30 40
22 33 33 55

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
		int n;
		cin >> n;
		int a[n], b[n];
		ll s = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			s += b[i] - a[i];
		}
		int id = 0;
		for (int i = 0; i < n; i++)
		{
			//b[i]+d=a0,an-1
			while (b[id] < a[i])
				id++;
			cout << b[id] - a[i] << " ";
		}
		cout << "\n";
		id = n - 1;
		int ans[n];
		for (int i = n - 1; i >= 0; i--)
		{
			if (i < n - 1) {
				if (a[i + 1] <= b[i])
				{
				}
				else
					id = i;
			}
			ans[i] = b[id] - a[i];
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}