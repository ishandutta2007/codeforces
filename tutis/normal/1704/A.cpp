/*input
10
6 2
001001
11
6 2
110111
01
6 2
000001
11
6 2
111111
01
8 5
10000101
11010
7 4
1010001
1001
8 6
01010010
010010
8 4
01010101
1001
8 4
10101010
0110
7 5
1011100
11100
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
		string a, b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		bool ok = false;
		for (int i = (int)b.size() - 1; i < a.size(); i++)
			if (a[i] == b.back())
				ok = true;
		for (int i = 0; i < (int)b.size() - 1; i++)
			if (b[i] != a[i])
				ok = false;
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}