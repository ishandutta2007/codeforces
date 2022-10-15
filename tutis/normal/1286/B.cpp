/*input
3
2 0
0 2
2 0

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int p[n + 1], c[n + 1];
	int sz[n + 1];
	int a[n + 1];
	vector<int>adj[n + 1];
	int r = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i] >> c[i];
		if (p[i] == 0)
			r = i;
		else
			adj[p[i]].push_back(i);
	}
	function<void(int, int)>pridek = [&](int i, int d)->void
	{
		a[i] += d;
		for (int j : adj[i])
		{
			pridek(j, d);
		}
	};
	vector<pair<int, int>>V;
	function<int(int, int)>dfs1 = [&](int i, int mx)->int
	{
		a[i] += mx;
		int ret = a[i];
		V.push_back({a[i], i});
		for (int j : adj[i])
		{
			ret = max(ret, dfs1(j, mx));
		}
		return ret;
	};
	function<void(int)>dfs = [&](int i)->void
	{
		sz[i] = 1;
		for (int j : adj[i])
		{
			dfs(j);
			sz[i] += sz[j];
		}
		if (sz[i] - 1 < c[i])
		{
			cout << "NO\n";
			exit(0);
		}
		V.clear();
		int mx = 0;
		for (int j : adj[i])
		{
			mx = dfs1(j, mx);
		}
		sort(V.begin(), V.end());
		if (c[i] == 0)
		{
			a[i] = 1;
			for (auto ii : V)
				a[ii.second]++;
		}
		else
		{
			int id = c[i] - 1;
			a[i] = a[V[id].second] + 1;
			for (int j = id + 1; j < V.size(); j++)
				a[V[j].second]++;
		}
	};
	dfs(r);
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
}