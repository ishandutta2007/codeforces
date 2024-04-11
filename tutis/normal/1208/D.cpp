/*input
5
0 1 1 1 10

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	ll l, r;
	ll mn;
	ll lazy = 0;
	ST *left, *right;
	ST(ll l, ll r, ll a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			mn = min(left->mn, right->mn);
		}
		else
		{
			mn = a[l];
		}
	}
	void fix()
	{
		mn += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(ll x, ll y, ll de)
	{
		fix();
		if (x <= l && r <= y)
		{
			lazy += de;
			return fix();
		}
		if (r < x || y < l)
			return;
		left->add(x, y, de);
		right->add(x, y, de);
		mn = min(left->mn, right->mn);
	}
	ll d()
	{
		fix();
		if (l == r)
			return l;
		right->fix();
		if (right->mn == 0)
			return right->d();
		else
			return left->d();
	}
	int get(int i)
	{
		fix();
		if (l == r)
			return mn;
		if (i <= (l + r) / 2)
			return left->get(i);
		else
			return right->get(i);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ST medis(0, n - 1, a);
	for (ll i = 1; i <= n; i++)
	{
		ll x = medis.d();
		a[x] = i;
		medis.add(x + 1, n - 1, -i);
		medis.add(x, x, 1e15);
	}
	for (ll i : a)
		cout << i << " ";
	cout << "\n";
}