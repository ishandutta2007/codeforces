/*input
5 5
25 36 39 40 899
1 1 3 2 7
2 1 2
1 3 5 9 1
1 4 4 0 9
2 1 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void merge(int *a, int *b)
{
	for (int i = 0; i < 10; i++)
		a[i] = b[a[i]];
}
struct ST
{
	int l, r;
	int a[10];
	ll sum[10];
	ST *left;
	ST *right;
	ST(ll l, ll r): l(l), r(r)
	{
		iota(a, a + 10, 0);
		fill(sum, sum + 10, 0ll);
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void add(int i, ll w, ll c)
	{
		if (!(l <= i && i <= r))
			return;
		sum[c] += w;
		if (l < r)
		{
			left->add(i, w, c);
			right->add(i, w, c);
		}
	}
	void fix()
	{
		ll sum1[10];
		fill(sum1, sum1 + 10, 0);
		for (ll t = 0; t < 10; t++)
			sum1[a[t]] += sum[t];
		if (l < r)
		{
			merge(left->a, a);
			merge(right->a, a);
		}
		iota(a, a + 10, 0);
		for (int i = 0; i < 10; i++)
			sum[i] = sum1[i];
	}
	void update(ll x, ll y, int *g)
	{
		if (x <= l && r <= y)
		{
			merge(a, g);
			fix();
			return;
		}
		fix();
		if (r < x || y < l)
			return;
		left->update(x, y, g);
		right->update(x, y, g);
		for (ll t = 0; t < 10; t++)
			sum[t] = left->sum[t] + right->sum[t];
	}
	ll summm(ll x, ll y)
	{
		if (x <= l && r <= y)
		{
			fix();
			ll summ = 0;
			for (ll t = 1; t < 10; t++)
				summ += t * sum[t];
			return summ;
		}
		fix();
		if (r < x || y < l)
			return 0;
		return left->summm(x, y) + right->summm(x, y);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, q;
	cin >> n >> q;
	ST X(1, n);
	for (ll i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		ll w = 1;
		reverse(a.begin(), a.end());
		for (char x : a)
		{
			X.add(i, w, x - '0');
			w *= 10;
		}
	}
	while (q--)
	{
		ll t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
		{
			ll x, y;
			cin >> x >> y;
			int a[10];
			iota(a, a + 10, 0);
			a[x] = y;
			X.update(l, r, a);
		}
		else
		{
			cout << X.summm(l, r) << "\n";
		}
	}
}