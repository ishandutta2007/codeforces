/*input
5
2 1 1 1 4
1 2
1 3
2 4
2 5

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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int>adj[n + 1];
	adj[0].push_back(1);
	adj[0].push_back(0);
	adj[1].push_back(0);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool ok[n + 1];
	map<int, int>M[n + 1];
	int cnt[n + 1];
	bool okp[n + 1];
	function<void(int, int)>dfs = [&](int i, int p)
	{
		adj[i].erase(find(adj[i].begin(), adj[i].end(), p));
		ok[i] = true;
		for (int j : adj[i])
		{
			dfs(j, i);
			ok[i] &= ok[j];
			if (M[j].size() > M[i].size())
				swap(M[i], M[j]);
			for (auto v : M[j])
				M[i][v.first] += v.second;
		}
		if ((++M[i][a[i]]) >= 2)
			ok[i] = false;
		if (i != 0)
		{
			if (M[i][a[p]] >= 1)
				okp[i] = false;
			else
				okp[i] = ok[i];
		}
		cnt[i] = M[i][a[i]];
	};
	dfs(0, 0);
	int ans = 0;
	function<void(int, bool)>dfs1 = [&](int i, bool ger)
	{
		if (ger && ok[i] && i != 0)
			ans++;
		vector<int>B;
		for (int j : adj[i])
			if (B.size() <= 1 && okp[j] == false)
				B.push_back(j);
		for (int j : adj[i])
		{
			bool ger_ = ger;
			if (M[0][a[j]] - cnt[j] > 0)
				ger_ = false;
			for (int k : B)
				if (k != j)
					ger_ = false;
			dfs1(j, ger_);
		}
	};
	dfs1(0, true);
	cout << ans << "\n";
	return 0;
}