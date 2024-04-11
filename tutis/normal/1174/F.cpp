/*input
5
1 2
1 3
3 4
3 5
2
5
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pa[202020][20];
vector<int>adj[202020];
int dep[202020];
int timer = 0;
int fr[202020];
int to[202020];
void dfs(int i, int p)
{
	fr[i] = to[i] = timer++;
	pa[i][0] = p;
	for (int t = 1; t < 20; t++)
		pa[i][t] = pa[pa[i][t - 1]][t - 1];
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dep[j] = dep[i] + 1;
		dfs(j, i);
		to[i] = to[j];
	}
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])
		swap(a, b);
	for (int t = 19; t >= 0; t--)
		if (dep[pa[a][t]] >= dep[b])
			a = pa[a][t];
	for (int t = 19; t >= 0; t--)
	{
		if (pa[a][t] != pa[b][t])
		{
			a = pa[a][t];
			b = pa[b][t];
		}
	}
	while (a != b)
	{
		a = pa[a][0];
		b = pa[b][0];
	}
	return a;
}
int d(int a, int b)
{
	return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}
int main()
{
	srand(12039);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dep[1] = 0;
	dfs(1, 1);
	vector<int>ok;
	for (int i = 1; i <= n; i++)
		ok.push_back(i);
	while (ok.size() > 1)
	{
		if (rand() % 2 == 0)
		{
			int u = ok[rand() % ok.size()];
			cout << "d " << u << endl;
			int x;
			cin >> x;
			if (x == -1)
				exit(5);
			vector<int>ok_;
			for (int i : ok)
			{
				if (d(i, u) == x)
					ok_.push_back(i);
			}
			ok = ok_;
		}
		else
		{
			int u = ok[0];
			for (int i = 1; i < ok.size(); i++)
				u = lca(u, ok[i]);
			if (find(ok.begin(), ok.end(), u) == ok.end())
			{
				cout << "s " << u << endl;
				int v;
				cin >> v;
				if (v == -1)
					exit(5);
				vector<int>ok_;
				for (int i : ok)
				{
					if (fr[v] <= fr[i] && fr[i] <= to[v])
						ok_.push_back(i);
				}
				ok = ok_;
			}
		}
	}
	cout << "! " << ok[0] << endl;
}