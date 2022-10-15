/*input
8
10 3
3 6 8
6 2
2 5
20 3
3 7 12
41 5
1 11 21 31 41
10 5
2 4 6 8 10
5 5
3 2 5 4 1
1000000000 1
1
1000000000 4
1 1000000000 10 16

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
		int n, m;
		cin >> n >> m;
		int a[m];
		for (int i = 0; i < m; i++)
			cin >> a[i];
		sort(a, a + m);
		vector<int>D;
		for (int i = 1; i < m; i++)
			D.push_back(a[i] - a[i - 1] - 1);
		D.push_back(a[0] - 1 + (n - a[m - 1]));
		sort(D.begin(), D.end(), greater<int>());
		int ans = m;
		int t = 0;
		for (int x : D)
		{
			int x_ = x;
			x -= 2 * t;
			if (x <= 0)
				ans += x_;
			else
			{
				ans += 2 * t;
				if (x == 1)
				{
					t++;
					continue;
				}
				else if (x == 2)
				{
					ans++;
					t++;
					continue;
				}
				else
				{
					ans++;
					t += 2;
				}
			}
		}
		cout << ans << "\n";
	}
}