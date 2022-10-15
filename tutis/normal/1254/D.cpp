/*input
5 12
1 2
1 3
2 4
2 5
1 1 1
2 1
2 2
2 3
2 4
2 5
1 2 2
2 1
2 2
2 3
2 4
2 5
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
vector<ll>adj[150150];
ll sz[150150];
ll de[150150];
const ll mod = 998244353;
ll pa[150150][20];
ll timer = 0;
ll l[150150], r[150150];
void dfs(ll i, ll p)
{
	de[i] = de[p] + 1;
	timer++;
	l[i] = timer;
	sz[i] = 1;
	pa[i][0] = p;
	for (ll t = 1; t < 20; t++)
		pa[i][t] = pa[pa[i][t - 1]][t - 1];
	for (ll j : adj[i])
	{
		if (j != p)
		{
			dfs(j, i);
			sz[i] += sz[j];
		}
	}
	r[i] = timer;
}
ll jau[150150];
vector<pair<ll, ll>>A;
ll X[150150];
void add(ll v, ll d)
{
	X[v] += d;
	if (X[v] >= mod)
		X[v] -= mod;
	A.push_back({v, d});
}
ll power(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * power(a, b - 1)) % mod;
	return power((a * a) % mod, b / 2);
}
ll up[150150];
ll in;
ll n, q;
ll s1[150150];
ll s2[150150];
void fix(ll v)
{
	if (X[v] == 0)
		return;
	jau[v] += X[v];
	if (jau[v] >= mod)
		jau[v] -= mod;
	for (ll u : adj[v])
	{
		if (u == pa[v][0])
		{
			ll s = (s2[v] * X[v]) % mod;
			up[1] += s;
			if (up[1] >= mod)
				up[1] -= mod;
			up[v] -= s;
			if (up[v] < 0)
				up[v] += mod;
		}
		else
		{
			up[u] = (up[u] + s1[u] * X[v]) % mod;
		}
	}
	X[v] = 0;
}
void dfs1(ll i, ll p)
{
	for (ll j : adj[i])
	{
		if (j != p)
		{
			up[j] += up[i];
			if (up[j] >= mod)
				up[j] -= mod;
			dfs1(j, i);
		}
	}
	jau[i] += up[i];
	if (jau[i] >= mod)
		jau[i] -= mod;
	up[i] = 0;
}
ll get(ll v)
{
	if (A.size() >= 480)
	{
		for (ll i = 1; i <= n; i++)
			fix(i);
		dfs1(1, 1);
		A.clear();
	}
	ull res = jau[v];
	for (pair<ll, ll>vd : A)
	{
		ll w = vd.first;
		ll d = vd.second;
		ll s = 0;
		if (v != w)
		{
			if (l[w] <= l[v] && r[v] <= r[w])
			{
				ll u = v;
				int x = de[u] - de[w] - 1;
				while (x > 0)
				{
					int a = x & -x;
					u = pa[u][__builtin_popcount(a - 1)];
					x ^= a;
				}
				res += d * s1[u];
				if (res >= 1.6e19)
					res %= mod;
			}
			else
			{
				res += d * s2[w];
				if (res >= 1.6e19)
					res %= mod;
			}
		}
		else
		{
			res += d;
		}

	}
	res %= mod;
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	in = power(n, mod - 2);
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
	{
		s1[i] = (1 - sz[i] * in) % mod;
		if (s1[i] < 0)
			s1[i] += mod;
		s2[i] = (1 - (n - sz[i]) * in) % mod;
		if (s2[i] < 0)
			s2[i] += mod;
	}
	while (q--)
	{
		ll t;
		cin >> t;
		if (t == 1)
		{
			ll v, d;
			cin >> v >> d;
			add(v, d);
		}
		else
		{
			ll v;
			cin >> v;
			cout << get(v) << "\n";
		}
	}
}