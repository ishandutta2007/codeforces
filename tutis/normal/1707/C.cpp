/*input
5 5
1 2
3 5
1 3
3 2
4 2
*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
struct ST
{
	int l, r;
	pair<ll, int> mx;
	ll lazy = 0;
	ST *left;
	ST *right;
	ST(int l, int r, int* a): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mx = {a[l], l};
		}
	}
	void fix()
	{
		mx.first += lazy;
		if (lazy != 0 && l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(int x, int y, ll val)
	{
		if (y < l || r < x)
			return fix();
		if (x <= l && r <= y)
		{
			lazy += val;
			fix();
		}
		else
		{
			fix();
			left->add(x, y, val);
			right->add(x, y, val);
			mx = max(left->mx, right->mx);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int pa[n + 1];
	for (int i = 0; i <= n; i++)
		pa[i] = i;
	function<int(int)>root = [&](int i)
	{
		if (i == pa[i])
			return i;
		return pa[i] = root(pa[i]);
	};
	vector<int>adj[n + 1];
	vector<int>med[n + 1];
	vector<pair<int, int>>blog;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (root(u) != root(v))
		{
			pa[root(u)] = root(v);
			med[u].push_back(v);
			med[v].push_back(u);
		}
		blog.push_back({u, v});
	}
	int pa1[n + 1][20];
	vector<int>c(n + 1, 0);
	vector<int>c1(n + 1, 0);
	int d[n + 1];
	function<void(int, int)>dfs = [&](int i, int p)
	{
		d[i] = d[p] + 1;
		pa1[i][0] = p;
		for (int t = 1; t < 20; t++)
			pa1[i][t] = pa1[pa1[i][t - 1]][t - 1];
		for (int j : med[i])
		{
			if (j != p)
				dfs(j, i);
		}
	};
	d[1] = 0;
	dfs(1, 1);
	auto lca = [&](int a, int b)
	{
		if (d[a] < d[b])
			swap(a, b);
		for (int t = 19; t >= 0; t--)
			if (d[pa1[a][t]] >= d[b])
				a = pa1[a][t];
		if (a == b)
			return a;
		for (int t = 19; t >= 0; t--)
			if (pa1[a][t] != pa1[b][t])
			{
				a = pa1[a][t];
				b = pa1[b][t];
			}
		return pa1[a][0];
	};
	int kiek = 0;
	for (auto i : blog)
	{
		int u = i.first;
		int v = i.second;
		int a = lca(u, v);
		if (a == u || a == v)
		{
			int x = a;
			int y = x ^ u ^ v;
			kiek++;
			c[y]++;
			c[1]++;
			int xx = y;
			for (int t = 19; t >= 0; t--)
				if (d[pa1[xx][t]] > d[x])
					xx = pa1[xx][t];
			c[xx]--;
		}
		else
		{
			kiek++;
			c[u]++;
			c[v]++;
		}
	}
	string ans(n, '1');
	function<void(int, int, int)>dfs1 = [&](int i, int p, int k)
	{
		k += c[i];
		if (k != kiek)
			ans[i - 1] = '0';
		k += c1[i];
		for (int j : med[i])
		{
			if (j != p)
				dfs1(j, i, k);
		}
	};
	dfs1(1, 1, 0);
	cout << ans << "\n";
}