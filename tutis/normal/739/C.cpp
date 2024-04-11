/*input
7
10 2 3 9 5 10 4
4
1 3 75
1 4 15
3 5 5
5 5 88
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	int l, r;
	ll L = 0, R = 0;
	ll lazy = 0;
	int mx;
	int x, y, z, t;

	ST *left;
	ST *right;
	void fix()
	{
		L += lazy;
		R += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void merge()
	{
		mx = max(left->mx, right->mx);
		L = left->L;
		R = right->R;
		x = left->x;
		y = left->y;
		z = right->z;
		t = right->t;
		if (x == left->r && left->R < right->L)
		{
			x = right->x;
			y = right->y;
		}
		else if (left->R > right->L && y == left->r)
		{
			if (right->x == right->l)
				y = right->y;
			else
				y++;
		}
		if (t == right->l && right->L < left->R)
		{
			z = left->z;
			t = left->t;
		}
		else if (left->R < right->L && z == right->l)
		{
			if (left->t == left->r)
				z = left->z;
			else
				z--;
		}
		if (z == l)
		{
			x = t;
			y = r;
		}
		if (y == r)
		{
			t = x;
			z = l;
		}
		if (left->R > right->L && right->x == right->l)
		{
			mx = max(mx, right->y - left->z + 1);
		}
		if (left->R > right->L)
		{
			mx = max(mx, left->r - left->z + 1 + 1);
		}
		if (left->R < right->L && left->t == left->r)
		{
			mx = max(mx, right->y - left->z + 1);
		}
		if (left->R < right->L)
		{
			mx = max(mx, right->y - right->l + 1 + 1);
		}
	}
	ST(ll l, ll r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
			merge();
		}
		else
		{
			mx = 1;
			x = y = z = t = l;
		}
	}
	void add(int a, int b, ll v)
	{
		if (a <= l && r <= b)
		{
			lazy += v;
			return fix();
		}
		fix();
		if (b < l || r < a)
			return;
		left->add(a, b, v);
		right->add(a, b, v);
		merge();
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ST X(1, n);
	for (ll i = 1; i <= n; i++)
	{
		ll a;
		cin >> a;
		X.add(i, i, a);
	}
	ll m;
	cin >> m;
	while (m--)
	{
		ll l, r, d;
		cin >> l >> r >> d;
		X.add(l, r, d);
		cout << X.mx << "\n";
	}
}