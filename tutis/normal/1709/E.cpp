/*input
5
2 2 2 2 2
1 2
2 3
3 4
4 5

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
	pair<int, int>get(int x, int y)
	{
		if (y < l || r < x)
			return { -1e18, -1};
		fix();
		if (x <= l && r <= y)
			return mx;
		return max(left->get(x, y), right->get(x, y));
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
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	set<int>S[n + 1];
	int offs[n + 1];
	int ans = 0;
	function<void(int, int)>dfs = [&](int i, int p)->void
	{
		S[i] = {};
		offs[i] = 0;
		bool ok = false;
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			dfs(j, i);
			if (S[j].size() > S[i].size())
			{
				swap(S[i], S[j]);
				swap(offs[i], offs[j]);
			}
			for (int v : S[j])
			{
				int r = v ^ offs[j];
				if (S[i].count(r ^ a[i] ^ offs[i]))
					ok = true;
			}
			for (int v : S[j])
			{
				int r = v ^ offs[j];
				S[i].insert(r ^ offs[i]);
			}
		}
		if (S[i].count(a[i] ^ offs[i]) != 0)
			ok = true;
		S[i].insert(offs[i]);
		offs[i] ^= a[i];
		if (ok == true)
		{
			S[i] = {};
			ans++;
		}
	};
	dfs(1, 1);
	cout << ans << "\n";
}