/*input
5 9
1 3 1
3 2 2
1 4 3
3 5 4
5 1 5
3 1 6
2 1 7
4 1 8
2 1 1
2 1 3
2 3 5
2 5 2
1 1 100
2 1 3
1 8 30
2 4 2
2 2 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct Fenwick
{
	vector<ll>A;
	ll n;
	Fenwick(ll n = 1): n(n)
	{
		A = vector<ll>(n + 1, 0);
	}
	inline ll lsb(ll x)
	{
		return ((x) & (-x));
	}
	void add(ll i, ll w)
	{
		for (; i <= n; i += lsb(i))
		{
			A[i] += w;
		}
	}
	ll get(ll i)
	{
		i = min(i, n);
		ll ret = 0;
		for (; i > 0; i -= lsb(i))
		{
			ret += A[i];
		}
		return ret;
	}
};
struct ST
{
	ll l, r;
	ll mn = 0;
	ST *left;
	ST *right;
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
		mn += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	ll get(ll a, ll b)
	{
		fix();
		if (a <= l && r <= b)
			return mn;
		if (r < a || b < l)
			return 1e17;
		return min(left->get(a, b), right->get(a, b));
	}
	void add(ll a, ll b, ll w)
	{
		fix();
		if (a <= l && r <= b)
		{
			lazy += w;
			return fix();
		}
		if (r < a || b < l)
			return;
		left->add(a, b, w);
		right->add(a, b, w);
		mn = min(left->mn, right->mn);
	}
	void set(ll i, ll w)
	{
		fix();
		if (l <= i && i <= r)
		{
			if (l == r)
			{
				mn = w;
				return;
			}
			left->set(i, w);
			right->set(i, w);
			mn = min(left->mn, right->mn);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	ll d1[n + 1];
	d1[1] = 0;
	vector<ll>adj[n + 1];
	ll a[2 * n];
	ll b[2 * n];
	ll c[2 * n];
	ll d[n + 1];
	d[1] = 0;
	for (ll i = 1; i <= 2 * n - 2; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		if (b[i] == 1)
			d1[a[i]] = c[i];
		else
		{
			adj[a[i]].push_back(b[i]);
			d[b[i]] = c[i];
		}
	}
	ll timer = 1;
	ll in[n + 1];
	ll out[n + 1];
	function<void(ll)>dfs = [&](ll i)
	{
		in[i] = out[i] = timer++;
		for (ll j : adj[i])
		{
			dfs(j);
			out[i] = out[j];
		}
	};
	dfs(1);
	Fenwick W(n + 3);
	for (ll i = 1; i <= n; i++)
	{
		W.add(in[i], d[i]);
		W.add(out[i] + 1, -d[i]);
	}
	ST XXX(in[1], out[1]);
	for (ll i = 1; i <= n; i++)
	{
		XXX.set(in[i], d1[i] + W.get(in[i]));
	}
	while (q--)
	{
		ll t;
		cin >> t;
		if (t == 2)
		{
			ll x, y;
			cin >> x >> y;
			if (in[x] <= in[y] && in[y] <= out[x])
			{
				cout << W.get(in[y]) - W.get(in[x]) << "\n";
			}
			else
			{
				cout << XXX.get(in[x], out[x]) - W.get(in[x]) + W.get(in[y]) << "\n";
			}
		}
		else
		{
			ll i, w;
			cin >> i >> w;
			if (b[i] == 1)
			{
				d1[a[i]] = w;
				ll c = a[i];
				XXX.set(in[c], d1[c] + W.get(in[c]));
			}
			else
			{
				W.add(in[b[i]], w - c[i]);
				W.add(out[b[i]] + 1, -(w - c[i]));
				XXX.add(in[b[i]], out[b[i]], w - c[i]);
				c[i] = w;
			}
		}
	}
}