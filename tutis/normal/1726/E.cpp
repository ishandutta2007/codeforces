/*input
10
2
3
4
5
6
7
8
9
10
50

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
mt19937 rng(0);
const ll mod = 998244353;
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
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a[300001];
	a[0] = a[1] = 1;
	for (int i = 2; i < 300001; i++)
		a[i] = (a[i - 1] + a[i - 2] * (i - 1)) % mod;
	int t;
	cin >> t;
	ll f[300001];
	f[0] = 1;
	for (int i = 1; i < 300001; i++)
		f[i] = (f[i - 1] * (2 * i - 1)) % mod;
	ll F[300001];
	F[0] = 1;
	for (int i = 1; i < 300001; i++)
		F[i] = (F[i - 1] * i) % mod;
	while (t--)
	{
		int n;
		cin >> n;
		ll ret = 0;
		for (int k = 0; k <= n / 4; k++)
		{
			ret += ((((F[n - 2 * k] * power(F[2 * k] * F[n - 4 * k], -1)) % mod) * power(2, k)) % mod) * ((f[k] * a[n - 4 * k]) % mod);
			ret %= mod;
		}
		cout << ret << "\n";
	}
	return 0;
}