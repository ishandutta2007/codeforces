/*input
13
1 3
2 3
3 4
3 5
3 6
6 7
7 8
8 9
9 10
10 11
11 12
11 13
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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	vector<int>F = {1, 1};
	while (F.back() <= 200000)
		F.push_back(F.back() + F[F.size() - 2]);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>>adj(n + 1);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int>sz(n + 1, 0);
	function<bool(int, int)>ans = [&](int i, int cnt)->bool
	{
		pair<int, int>mn = {cnt + 1, i};
		function<void(int, int)>dfs = [&](int i, int p)
		{
			sz[i] = 1;
			int mx = 0;
			for (int j : adj[i])
			{
				if (j != p)
				{
					dfs(j, i);
					sz[i] += sz[j];
					mx = max(mx, sz[j]);
				}
			}
			mx = max(mx, cnt - sz[i]);
			mn = min(mn, {mx, i});
		};
		dfs(i, i);
		assert(sz[i] == cnt);
		if (cnt <= 3)
			return true;
		auto it = lower_bound(F.begin(), F.end(), sz[i]);
		if ((*it) != sz[i])
			return false;
		int id = it - F.begin();
		vector<pair<int, pair<int, int>>>c2, c3;
		function<void(int, int, int c)>dfs1 = [&](int i, int p, int c)
		{
			sz[i] = 1;
			int mx = 0;
			for (int j : adj[i])
			{
				if (j != p)
				{
					dfs1(j, i, c);
					sz[i] += sz[j];
				}
			}
			if (sz[i] == F[id - 2])
			{
				c2.push_back({i, {p, c}});
			}
			else if (sz[i] == F[id - 3])
			{
				c3.push_back({i, {p, c}});
			}
		};
		auto rem = [&](int x, int y)
		{
			adj[x].erase(find(adj[x].begin(), adj[x].end(), y));
			adj[y].erase(find(adj[y].begin(), adj[y].end(), x));
		};
		auto add = [&](int x, int y)
		{
			adj[x].push_back(y);
			adj[y].push_back(x);
		};
		for (int j : adj[mn.second])
			dfs1(j, mn.second, j);
		if (c2.empty())
			return false;
		if (c2.size() == 1)
		{
			rem(c2[0].first, c2[0].second.first);
			if (ans(mn.second, F[id - 1]) && ans(c2[0].first, F[id - 2]))
			{
				add(c2[0].first, c2[0].second.first);
				return true;
			}
			add(c2[0].first, c2[0].second.first);
			return false;
		}
		assert(c2.size() == 2);
		rem(c2[0].first, c2[0].second.first);
		rem(c2[1].first, c2[1].second.first);
		bool ger[2] = {ans(c2[0].first, F[id - 2]), ans(c2[1].first, F[id - 2])};
		if (ans(mn.second, F[id - 3]) && ger[0] && ger[1])
		{
			add(c2[0].first, c2[0].second.first);
			add(c2[1].first, c2[1].second.first);
			return true;
		}
		add(c2[0].first, c2[0].second.first);
		add(c2[1].first, c2[1].second.first);
		return false;
	};
	if (ans(1, n))
		cout << "YES\n";
	else
		cout << "NO\n";
}