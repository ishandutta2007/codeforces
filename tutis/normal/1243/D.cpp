/*input
3 0

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int pa[n + 1];
	iota(pa, pa + n + 1, 0);
	int sz[n + 1];
	fill_n(sz, n + 1, 1);
	set<int>tevai;
	for (int i = 1; i <= n; i++)
		tevai.insert(i);
	function<int(int)>root = [&](int x)
	{
		if (pa[x] == x)
			return x;
		return pa[x] = root(pa[x]);
	};
	int ans = n - 1;
	auto merge = [&](int x, int y)
	{
		x = root(x);
		y = root(y);
		if (x == y)
			return;
		sz[y] += sz[x];
		pa[x] = y;
		sz[x] = 0;
		ans--;
		tevai.erase(x);
	};
	vector<int>adj[n + 1];
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j : adj[i])
		{
			sz[root(j)]--;
			if (sz[root(j)] == 0)
				tevai.erase(root(j));
		}
		set<int>tt = tevai;
		for (int j : adj[i])
		{
			tevai.insert(root(j));
			sz[root(j)]++;
		}
		for (int j : tt)
		{
			merge(j, i);
		}
	}
	cout << ans << "\n";
}