/***
5 4
0 1 5 6 7
1
1
4
5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
inline ll power(ll b)
{
	return (1ll) << (b);
}
struct SegTree
{
	ll a, b;
	ll kiek;
	SegTree *left;
	SegTree *right;
	inline void init(ll l, ll r)
	{
		a = l;
		b = r;
		kiek = b - a + 1;
		if (a < b)
		{
			left = new SegTree;
			right = new SegTree;
			ll sz = 1;
			while (sz * 2 < b - a + 1)
				sz *= 2;
			left->init(a, a + sz - 1);
			right->init(a + sz, b);
		}
	}
	inline void add(ll s)
	{
		if (a <= s && s <= b)
		{
			if (a < b)
			{
				left->add(s);
				right->add(s);
				kiek = left->kiek + right->kiek;
			}
			else
				kiek = 0;
		}
	}
	inline ll get(ll l, ll r)
	{
		if (l > b || r < a)
			return 0;
		if (l <= a && b <= r)
			return kiek;
		if (a < b)
			return left->get(l, r) + right->get(l, r);
		return 0;
	}
};
int main(void)
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	SegTree *X = new SegTree;
	X->init(0, power(19));
	ll n, q;
	cin >> n >> q;
	while (n--)
	{
		ll a;
		cin >> a;
		X->add(a);
	}
	ll x = 0;
	while (q--)
	{
		ll p;
		cin >> p;
		x ^= p;
		ll ans = 0;
		ll nuo = 0;
		for (ll i = 19; i >= 0; i--)
		{
			ll a = ((x) & power(i));
			if (a == 0)
			{
				if (X->get(nuo, nuo + power(i) - 1) == 0)
				{
					ans += power(i);
					nuo += power(i);
				}
			}
			else
			{
				if (X->get(nuo + power(i), nuo + power(i + 1) - 1) == 0)
				{
					ans += power(i);
				}
				else
					nuo += power(i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}