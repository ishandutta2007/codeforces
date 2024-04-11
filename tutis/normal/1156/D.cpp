/*input
7
2 1 1
3 2 0
4 2 1
5 2 0
6 7 1
7 2 1
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>adj[202020][2];
struct dsu
{
	int pa[202020];
	dsu()
	{
		fill_n(pa, 202020, -1);
	}
	int root(int x)
	{
		if (pa[x] < 0)
			return x;
		return pa[x] = root(pa[x]);
	}
	void merge(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a != b)
		{
			pa[b] += pa[a];
			pa[a] = b;
		}
	}
	ll size(int i)
	{
		return -pa[root(i)];
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<bool>yra[2];
	yra[0] = yra[1] = vector<bool>(n + 2, false);
	for (int i = 1; i < n; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		adj[x][c].push_back(i);
		adj[y][c].push_back(i);
		yra[c][i] = true;
	}
	ll ans = 0;
	dsu xxx[2];
	for (int i = 1; i <= n; i++)
	{
		for (int c = 0; c < 2; c++)
		{
			for (int t = 1; t < (int)adj[i][c].size(); t++)
			{
				xxx[c].merge(adj[i][c][t], adj[i][c][t - 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (adj[i][0].empty())
			continue;
		if (adj[i][1].empty())
			continue;
		ans += (xxx[1].size(adj[i][1][0])) * (xxx[0].size(adj[i][0][0]));
	}
	for (int c : {0, 1})
	{
		for (int i = 1; i < n; i++)
		{
			if (xxx[c].root(i) != i || yra[c][i] == false)
				continue;
			ll s = xxx[c].size(i) + 1;
			ans += s * s - s;
		}
	}
	cout << ans << "\n";
}