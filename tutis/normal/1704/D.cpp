/*input
7
3 9
0 1 2 0 0 2 1 1 0
0 1 1 1 2 0 0 2 0
0 1 2 0 0 1 2 1 0
3 7
25 15 20 15 25 20 20
26 14 20 14 26 20 20
25 15 20 15 20 20 25
3 9
25 15 20 15 25 20 20 20 20
26 14 20 14 26 20 20 20 20
25 15 20 15 25 15 20 20 25
3 11
25 15 20 15 25 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20
25 15 20 15 25 20 15 20 20 20 25
3 13
25 15 20 15 25 20 20 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20 20 20
25 15 20 15 25 20 20 15 20 20 20 20 25
3 15
25 15 20 15 25 20 20 20 20 20 20 20 20 20 20
26 14 20 14 26 20 20 20 20 20 20 20 20 20 20
25 15 20 15 25 20 20 20 15 20 20 20 20 20 25
3 9
909459 479492 676924 224197 162866 164495 193268 742456 728277
948845 455424 731850 327890 304150 237351 251763 225845 798316
975446 401170 792914 272263 300770 242037 236619 334316 725899

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
const ll mods[2] = {(ll)1e9 + 7, (ll)1e9 + 9};
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
		ll c[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> c[i][j];
		array<ll, 2> s[n];
		for (int i = 0; i < n; i++)
		{
			for (int t : {0, 1})
			{
				ll a[m];
				for (int j = 0; j < m; j++)
					a[j] = c[i][j] % mods[t];
				for (int r : {0, 1})
					for (int j = 1; j < m; j++)
					{
						a[j] += a[j - 1];
						if (a[j] >= mods[t])
							a[j] -= mods[t];
					}
				s[i][t] = a[m - 1];
			}
		}
		for (int k = 0; k < n; k++)
		{
			int c = 0;
			for (int i = 0; i < 3; i++)
				if (i != k && s[k] != s[i])
					c++;
			if (c >= 2)
			{
				int i = 0;
				if (k == 0)
					i = 1;
				ll x0 = (-s[k][0] + s[i][0] + mods[0]) % mods[0];
				ll x1 = (-s[k][1] + s[i][1] + mods[1]) % mods[1];
				ll x = (x0 - x1 + mods[0]) % mods[0];
				x *= power(mods[1], -1);
				x %= mods[0];
				ll c = x0 + x * mods[1];
				cout << k + 1 << " " << c << "\n";
			}
		}
	}
}