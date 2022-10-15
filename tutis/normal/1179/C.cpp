/*input
1 1
1
1
1
1 1 100

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	ll l, r;
	ST *left = NULL;
	ST *right = NULL;
	ll mx = 0;
	ll lazy = 0;
	ST(ll l, ll r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void fix()
	{
		mx += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(ll x, ll y, ll w)
	{
		fix();
		if (x <= l && r <= y)
		{
			lazy += w;
			return fix();
		}
		if (r < x || y < l)
			return;
		left->add(x, y, w);
		right->add(x, y, w);
		mx = max(left->mx, right->mx);
	}
	ll answer()
	{
		fix();
		if (l < r)
		{
			if (right->mx + right->lazy > 0)
				return right->answer();
			if (left->mx + left->lazy > 0)
				return left->answer();
			return -1;
		}
		if (mx > 0)
			return r;
		return -1;
	}
} medis(0, 1010101);
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll a[n + 1];
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		medis.add(0, a[i], 1);
	}
	ll b[m + 1];
	for (ll i = 1; i <= m; i++)
	{
		cin >> b[i];
		medis.add(0, b[i], -1);
	}
	ll q;
	cin >> q;
	while (q--)
	{
		ll t, i, x;
		cin >> t >> i >> x;
		if (t == 1)
		{
			medis.add(0, a[i], -1);
			a[i] = x;
			medis.add(0, a[i], 1);
		}
		else
		{
			medis.add(0, b[i], 1);
			b[i] = x;
			medis.add(0, b[i], -1);
		}
		cout << medis.answer() << "\n";
	}
}