/*input
3
1 2
2 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[404040];
int sz[404040];
int n;
vector<int>cc;
void dfs(int i, int p)
{
	sz[i] = 1;
	int mx = 0;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
		sz[i] += sz[j];
		mx = max(mx, sz[j]);
	}
	mx = max(mx, n - sz[i]);
	if (mx <= n / 2)
		cc.push_back(i);
}
int ans[404040];
void pildyk(int i, int p, int x)
{
	if (n - sz[i] - x <= n / 2)
		ans[i] = 1;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		pildyk(j, i, x);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1);
	vector<int>x = cc;
	for (int c : x)
	{
		dfs(c, c);
		ans[c] = 1;
		multiset<int, greater<int>>ss;
		for (int i : adj[c])
		{
			ss.insert(sz[i]);
		}
		for (int i : adj[c])
		{
			ss.erase(ss.find(sz[i]));
			pildyk(i, c, *ss.begin());
			ss.insert(sz[i]);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}