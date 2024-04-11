/*input
4 1
1 2
1 3
1 4

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
struct ST
{
	int l, r;
	pair<int, int> mx;
	int lazy = 0;
	ST *left;
	ST *right;
	ST(int l, int r, int d[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, d);
			right = new ST((l + r) / 2 + 1, r, d);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mx = {d[l], l};
		}
	}
	void fix()
	{
		if (lazy != 0)
		{
			if (l < r)
			{
				left->lazy += lazy;
				right->lazy += lazy;
			}
			mx.first += lazy;
		}
		lazy = 0;
	}
	void add(int x, int y, int delt)
	{
		fix();
		if (y < l || r < x)
			return;
		if (x <= l && r <= y)
		{
			lazy += delt;
			return fix();
		}
		left->add(x, y, delt);
		right->add(x, y, delt);
		mx = max(left->mx, right->mx);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int pa[n + 1];
	int fr[n + 1], to[n + 1];
	int id[n + 1];
	int dep[n + 1];
	function<void(int, int, int)>dfs = [&](int i, int p, int d)
	{
		to[i] = fr[i];
		id[fr[i]] = i;
		dep[fr[i]] = d;
		pa[i] = p;
		for (int j : adj[i])
		{
			if (j != p)
			{
				fr[j] = to[i] + 1;
				dfs(j, i, d + 1);
				to[i] = to[j];
			}
		}
	};
	fr[1] = 1;
	dfs(1, 1, 1);
	ST medis(fr[1], to[1], dep);
	vector<bool>yra(n + 1, true);
	ll best = 0;
	ll x = n / 2;
	best = -x * (n - x);
	ll res = -n;
	ll w = 0;
	ll r = 0;
	while (k--)
	{
		int i = id[medis.mx.second];
		res++;
		int c = 0;
		while (yra[i])
		{
			medis.add(fr[i], to[i], -1);
			yra[i] = false;
			c++;
			w++;
			i = pa[i];
		}
		r++;
		w--;
		res += c;
		ll hi = -res + r;
		ll lo = 0;
		ll gal = w * res;
		for (ll bb : {n / 2, (n - 1) / 2, 0ll, hi, (n + 1) / 2})
		{
			ll b = bb;
			if (b >= 0 && b <= hi)
			{
				gal = min(gal, (n - r - b) * (r - b));
			}
		}
		best = max(best, gal);
	}
	cout << best << "\n";
}