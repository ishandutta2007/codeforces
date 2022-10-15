/*input
10 20
1 2 0
4 3 3
6 8 7
10 1 4
3 8 0
10 7 0
9 7 9
7 1 10
6 7 2
8 5 10
4 5 7
10 4 2
6 9 10
6 10 10
10 5 5
4 1 4
9 8 0
2 3 7
4 7 4
3 1 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1000000007;
struct DSU
{
	vector<ll>pa;
	DSU(ll n)
	{
		n += 5;
		pa = vector<ll>(n, -1);
	}
	ll root(ll x)
	{
		if (pa[x] < 0)
			return x;
		return pa[x] = root(pa[x]);
	}
	void merge(ll a, ll b)
	{
		a = root(a);
		b = root(b);
		if (a == b)
			return;
		if (pa[a] < pa[b])
			swap(a, b);
		pa[b] += pa[a];
		pa[a] = b;
	}
};
ll xx[101010];
vector<ll>compress(vector<ll> &xx)
{
	ll A[61];
	fill_n(A, 61, 0);
	vector<ll>ret;
	for (ll x : xx)
	{
		for (ll i = 60; i >= 0; i--)
		{
			if ((x & (1ll << i)) > 0)
				x ^= A[i];
		}
		for (ll i = 60; i >= 0; i--)
		{
			if ((x & (1ll << i)) > 0)
			{
				A[i] = x;
				ret.push_back(x);
				break;
			}
		}
	}
	return ret;
}
vector<ll>visi[101010];
ll buvo[101010];
ll solve(vector<pair<ll, ll>>adj[], ll root)
{
	vector<ll>xors;
	for (ll i = 0; i <= 60; i++)
		xx[i] = 0;
	for (auto i : adj[root])
		visi[i.first].push_back(i.second);
	for (auto i : adj[root])
	{
		if (!buvo[i.first])
		{
			for (ll x : visi[i.first])
			{
				ll y=visi[i.first][0];
					xors.push_back(x ^ y);
				
			}
		}
		buvo[i.first] = true;
	}
	xors = compress(xors);
	set<ll>v = {root};
	for (auto i : adj[root])
		v.insert(i.first);
	xx[root] = 0;
	for (auto i : adj[root])
		xx[i.first] = i.second;
	ll ret = 0;
	pair<ll, ll> a[61];
	for (ll i = 0; i <= 60; i++)
	{
		a[i] = {0, 1ll << i};
		a[i].second %= modulo;
		for (ll c : xors)
		{
			if ((c & (1ll << i)) > 0)
			{
				a[i] = {(a[i].first + a[i].second) % modulo, (a[i].second + a[i].first) % modulo};
			}
			else
			{
				a[i] = {(a[i].first * 2) % modulo, (a[i].second * 2) % modulo};
			}
		}
	}
	ll K[61][2];
	for (ll i = 0; i <= 60; i++)
		K[i][0] = K[i][1] = 0;
	for (ll x : v)
	{
		ll cc = xx[x];
		for (ll i = 0; i <= 60; i++)
		{
			if ((cc & (1ll << i)) == 0)
			{
				ret += a[i].first * K[i][0];
				ret += a[i].second * K[i][1];
				K[i][0]++;
			}
			else
			{
				ret += a[i].first * K[i][1];
				ret += a[i].second * K[i][0];
				K[i][1]++;
			}
			ret %= modulo;
		}
	}
	return ret;
}
vector<pair<ll, ll>>adj[101010];
vector<pair<ll, ll>>adj1[101010];
vector<ll>d(101010, -1);
ll f(vector<ll>c)
{
	if (c.size() <= 1)
		return 0;
	d[c[0]] = 0;
	queue<ll>Q;
	Q.push(c[0]);
	while (!Q.empty())
	{
		ll a = Q.front();
		Q.pop();
		for (pair<ll, ll>b : adj[a])
		{
			adj1[c[0]].push_back({b.first, d[a] ^ b.second});
			adj1[b.first].push_back({c[0], d[a] ^ b.second});
			if (d[b.first] == -1)
			{
				d[b.first] = d[a] ^ b.second;
				Q.push(b.first);
			}
		}
	}
	return solve(adj1, c[0]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	DSU G(n);
	while (m--)
	{
		ll u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
		G.merge(u, v);
	}
	ll ans = 0;
	vector<ll>comp[n + 1];
	for (ll i = 1; i <= n; i++)
		comp[G.root(i)].push_back(i);
	for (ll i = 1; i <= n; i++)
	{
		ans += f(comp[i]);
		ans %= modulo;
	}
	cout << ans << "\n";
}