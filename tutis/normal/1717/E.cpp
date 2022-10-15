/*input
69228

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
mt19937_64 rng(0);
const ll mod = 1e9 + 7;
ll p(ll x, ll y)
{
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
	int n;
	cin >> n;
	vector<int>d[n + 1];
	int P[n + 1];
	for (int x = 1; x <= n; x++)
		P[x] = x;
	for (int x = 1; x <= n; x++)
	{
		if (d[x].size() == 1 && x != 1)
		{
			for (int y = x; y <= n; y += x)
				P[y] -= P[y] / x;
		}
		for (int y = x; y <= n; y += x)
			d[y].push_back(x);
	}
	ll ret = 0;
	for (int c = 1; c <= n - 2; c++)
	{
		int k = n - c;
		ret -= ((1ll * c * (n - c) / __gcd(c, (n - c))));
		for (int g : d[n - c])
		{
			ret += ((1ll * P[(n - c) / g] * c * g / __gcd(c, g)));
			ret %= mod;
		}
	}
	ret %= mod;
	ret += mod;
	ret %= mod;
	cout << ret << "\n";
	return 0;
}