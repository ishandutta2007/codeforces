/*input
5 6 5
0 9 4 0 10
1 2
1 3
2 3
3 4
1 4
4 5

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
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
ll aa[303030];
struct cc
{
	bool operator()(int x, int y)const
	{
		if (aa[x] != aa[y])
			return aa[x] > aa[y];
		else
			return x < y;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, X;
	cin >> n >> m >> X;
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		aa[i] = a[i];
	}
	vector<pair<int, int>>E(m);
	for (auto &i : E)
		cin >> i.first >> i.second;
	map<int, int, cc>adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		adj[E[i].first][E[i].second] = i;
		adj[E[i].second][E[i].first] = i;
	}
	vector<int>ans;
	vector<pair<pair<int, int>, int>>G;
	int r[n + 1];
	for (int i = 0; i <= n; i++)
		r[i] = i;
	function<int(int)>root = [&](int x)
	{
		if (r[x] == x)
			return x;
		else
			return r[x] = root(r[x]);
	};
	auto merge = [&](int x, int y, int i)
	{
		x = root(x);
		y = root(y);
		if (x != y)
		{
			if (a[x] + a[y] >= X)
			{
				if (adj[x].size() > adj[y].size())
					swap(x, y);
				adj[x].erase(y);
				adj[y].erase(x);
				for (auto i : adj[x])
				{
					adj[i.first].erase(x);
					adj[i.first][y] = i.second;
				}
				for (auto i : adj[x])
				{
					adj[y].insert(i);
				}
				r[x] = y;
				a[y] = a[y] + a[x] - X;
				ans.push_back(i + 1);
				return true;
			}
		}
		return false;
	};
	queue<int>Q;
	vector<bool>inq(n + 1, true);
	for (int i = 1; i <= n; i++)
		Q.push(i);
	while (!Q.empty())
	{
		int i = Q.front();
		Q.pop();
		inq[i] = false;
		if (root(i) != i)
			continue;
		bool ok = false;
		for (auto j : adj[i])
		{
			if (merge(i, j.first, j.second))
			{
				ok = true;
				if (inq[root(i)] == false)
					Q.push(root(i));
				inq[root(i)] = true;
				break;
			}
		}
	}
	if (ans.size() == n - 1)
	{
		cout << "YES\n";
		for (int i : ans)
			cout << i << "\n";
	}
	else
		cout << "NO\n";
}