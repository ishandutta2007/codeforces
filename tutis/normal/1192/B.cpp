/*input
10 10 10000
1 9 1241
5 6 1630
10 5 1630
2 6 853
10 1 511
5 3 760
8 3 1076
4 10 1483
7 10 40
8 2051
5 6294
5 4168
7 1861
0 5244
6 5156
3 3001
8 5267
5 3102
8 3623
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	ll l, r;
	pair<ll, ll>mx;
	ll lazy = 0;
	ST *left;
	ST *right;
	ST(ll l, ll r, ll w = 0): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, w);
			right = new ST((l + r) / 2 + 1, r, w);
		}
		mx = {w, r};
	}
	void fix()
	{
		mx.first += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(ll x, ll y, ll w)
	{
		if (x <= l && r <= y)
		{
			lazy += w;
			return fix();
		}
		fix();
		if (r < x || y < l)
			return;
		left->add(x, y, w);
		right->add(x, y, w);
		mx = max(left->mx, right->mx);
	}
	void set(ll i, ll w)
	{
		fix();
		if (l < r)
		{
			if (i <= (l + r) / 2)
				left->set(i, w);
			else
				right->set(i, w);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mx = {w, r};
		}
	}
	pair<ll, ll>get(ll x, ll y)
	{
		fix();
		if (x <= l && r <= y)
		{
			return mx;
		}
		if (r < x || y < l)
			return { -2e18, -2};
		return max(left->get(x, y), right->get(x, y));
	}
} medis(0, 101010), medis1(0, 101010, -2e18);
vector<ll>adj[101010];
ll sz[101010];
ll timer = 1;
ll nuo[101010];
ll iki[101010];
ll pa[101010][20];
ll dd[101010];
void dfs(ll i, ll p)
{
	pa[i][0] = p;
	for (ll t = 1; t < 20; t++)
		pa[i][t] = pa[pa[i][t - 1]][t - 1];
	sz[i] = 1;
	pair<ll, ll>mx = { -1, 0};
	for (ll t = 0; t < (ll)adj[i].size(); t++)
	{
		ll j = adj[i][t];
		if (j == p)
			continue;
		dd[j] = dd[i] + 1;
		dfs(j, i);
		sz[i] += sz[j];
		mx = max(mx, {sz[j], t});
	}
	swap(adj[i][0], adj[i][mx.second]);
}
ll head[101010];
ll zem[101010];
void dfs1(ll i, ll p, ll h)
{
	head[i] = h;
	nuo[i] = iki[i] = timer++;
	ll x = 0;
	for (ll j : adj[i])
	{
		x++;
		if (j == p)
			continue;
		if (x == 1)
		{
			zem[i] = j;
			dfs1(j, i, h);
		}
		else
			dfs1(j, i, j);
		iki[i] = iki[j];
	}
}
ll a[101010], b[101010], c[101010];
ll W[101010];
ll n, q, w;
void add(ll i, ll w)
{
	ll v = (sz[a[i]] < sz[b[i]] ? a[i] : b[i]);
	if (n <= 5000 && q <= 5000)
	{
		W[v] += w;
		return;
	}
	medis.add(nuo[v], iki[v], w);
	medis1.add(nuo[v], iki[v], -w);
	while (true)
	{
		v = head[v];
		if (v == 1)
			break;
		ll p = pa[v][0];
		ll Dp = medis.get(nuo[p], nuo[p]).first;
		if (zem[p] != 0)
		{
			ll Du = max(medis.get(nuo[p], nuo[zem[p]] - 1),
			            medis.get(iki[zem[p]] + 1, iki[p])).first;
			medis1.set(nuo[p], Du - 2 * Dp);
		}
		v = p;
	}
}
ll last = 0;
ll H[101010];
void dfs2(int i, int p)
{
	H[i] = 0;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs2(j, i);
		last = max(last, H[i] + W[j] + H[j]);
		H[i] = max(H[i], H[j] + W[j]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> q >> w;
	for (ll i = 0; i < n - 1; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	dfs(1, 1);
	dfs1(1, 1, 1);
	for (ll i = 0; i < n - 1; i++)
		add(i, c[i]);
	ll kas[n + 10];
	for (ll i = 1; i <= n; i++)
		kas[nuo[i]] = i;
	for (int ccc = 0; ccc < q; ccc++)
	{
		ll d, e;
		cin >> d >> e;
		d = (d + last) % (n - 1);
		e = (e + last) % w;
		add(d, e - c[d]);
		c[d] = e;
		last = 0;
		if (n <= 5000 && q <= 5000)
		{
			dfs2(1, 1);
			cout << last << "\n";
			continue;
		}
		ll v = kas[medis.get(nuo[1], iki[1]).second];
		ll Dv = medis.get(nuo[v], nuo[v]).first;
		last = Dv;
		while (v != 1)
		{
			ll p = pa[v][0];
			ll Du = max(medis.get(nuo[p], nuo[v] - 1),
			            medis.get(iki[v] + 1, iki[p])).first;
			ll Dp = medis.get(nuo[p], nuo[p]).first;
			last = max(last, Dv + Du - 2 * Dp);
			v = p;
			if (head[v] == v || zem[v] == 0 || dd[v] <= 30)
				v = p;
			else
			{
				last = max(last, Dv + medis1.get(nuo[head[v]], nuo[v] - 1).first);
				v = head[v];
			}
		}
		cout << last << "\n";
	}
}