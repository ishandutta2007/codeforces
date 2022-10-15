/*input
2 5
152 29
TOTIENT 1 2
TOTIENT 2 2
TOTIENT 1 2
TOTIENT 1 1
MULTIPLY 1 1 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename A>
using ordered_set = tree<A, null_type, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
const ll modulo = 1000000007;
inline ll mod(ll x, ll m = modulo)
{
	x %= m;
	if (x < 0)
		return x + m;
	return x;
}
inline ll power(ll x, ll a)
{
	x = mod(x);
	if (a < 0)
		a = mod(a, modulo - 1);
	ll ret = 1;
	ll k = 1;
	while (a)
	{
		if ((k & a) > 0)
		{
			a ^= k;
			ret = mod(ret * x);
		}
		k <<= 1;
		x = mod(x * x);
	}
	return ret;
}
ll inv(ll x)
{
	return power(x, -1);
}
ll P[350];
struct ST
{
	ll l, r;
	ll sand = 1;
	ll lazy = 1;
	ST* left;
	ST* right;
	ST(ll l, ll r, ll a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			sand = (left->sand * right->sand) % modulo;
		}
		else
		{
			sand = a[l];
		}
	}
	void fix()
	{
		if (lazy != 1)
		{
			sand = mod(sand * power(lazy, r - l + 1));
			if (l < r)
			{
				left->lazy = mod(left->lazy * lazy);
				right->lazy = mod(right->lazy * lazy);
			}
			lazy = 1;
		}
	}
	void mult(ll x, ll y, ll a)
	{
		if (x <= l && r <= y)
		{
			lazy = mod(lazy * a);
			return fix();
		}
		if (r < x || y < l)
			return fix();
		fix();
		left->mult(x, y, a);
		right->mult(x, y, a);
		sand = mod(left->sand * right->sand);
	}
	ll sandauga(ll x, ll y)
	{
		fix();
		if (x <= l && r <= y)
		{
			return sand;
		}
		if (r < x || y < l)
			return 1;
		return mod(left->sandauga(x, y) * right->sandauga(x, y));
	}
};
struct ST1
{
	ll l, r;
	ll suma = 0;
	ll lazy = 0;
	ST1* left;
	ST1* right;
	ST1()
	{

	}
	ST1(ll l, ll r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST1(l, (l + r) / 2);
			right = new ST1((l + r) / 2 + 1, r);
		}
	}
	void fix()
	{
		suma |= lazy;
		if (l < r)
		{
			left->lazy |= lazy;
			right->lazy |= lazy;
		}
	}
	void pridek(ll x, ll y, ll z)
	{
		if (x <= l && r <= y)
		{
			lazy |= z;
			return fix();
		}
		if (r < x || y < l)
			return fix();
		fix();
		suma |= z;
		left->pridek(x, y, z);
		right->pridek(x, y, z);
	}
	ll SUMA(ll x, ll y)
	{
		fix();
		if (x <= l && r <= y)
		{
			return suma;
		}
		if (r < x || y < l)
			return 0;
		return (left->SUMA(x, y) | right->SUMA(x, y));
	}
} medziai(0, 400000);
ll id[350];
ll timer = 0;
ll X[350];
int main()
{
	ios_base::sync_with_stdio(false);
	for (ll i = 2; i <= 300; i++)
	{
		if (P[i] == 0)
		{
			for (ll j = i; j <= 300; j += i)
			{
				if (P[j] == 0)
					P[j] = i;
			}
			id[i] = timer++;
			X[id[i]] = mod(1 - inv(i));
		}
	}
	ll n, q;
	cin >> n >> q;
	ll a[n + 1];
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		ll x = a[i];
		while (x != 1)
		{
			ll p = P[x];
			medziai.pridek(i, i, 1ll << (id[p]));
			x /= p;
		}
	}
	ST medis(1, n, a);
	while (q--)
	{
		string a;
		ll l, r;
		cin >> a >> l >> r;
		if (a == "MULTIPLY")
		{
			ll x;
			cin >> x;
			medis.mult(l, r, x);
			while (x != 1)
			{
				ll p = P[x];
				medziai.pridek(l, r, 1ll << id[p]);
				x /= p;
			}
		}
		else
		{
			ll ret = medis.sandauga(l, r);
			ll z = medziai.SUMA(l, r);
			while (z > 0)
			{
				ll z_ = z & (-z);
				ret = mod(ret * X[__builtin_ctzll(z_)]);
				z ^= z_;
			}
			cout << ret << "\n";
		}
	}
}