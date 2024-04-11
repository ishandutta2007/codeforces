/*input
3 2 2
1 2
3 2
1 3
2 1
*/
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[202020];
int mark[202020];
int R[202020];
int Num[202020];
int dabar = 1;
set<pair<int, int>>bridges;
map<pair<int, int>, int>G;
bool buvau[202020];
int dfs(int i, int p)
{
	buvau[i] = true;
	if (mark[i])
		return R[i];
	if (Num[i] == 0)
		Num[i] = dabar++;
	R[i] = Num[i];
	mark[i] = true;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		int x = min(i, j);
		int y = max(i, j);
		if (dfs(j, i) > Num[i] && G[ {x, y}] <= 1)
		{
			bridges.insert(make_pair(x, y));
		}
		R[i] = min(R[i], dfs(j, i));
	}
	return R[i];
}
int C[202020];
int D[202020];
int dfs(int i)
{
	if (C[i] == 0)
		C[i] = i;
	else
	{
		D[i]++;
		if (D[i] >= 2)
			return 0;
	}
	for (int j : adj[i])
	{
		if (bridges.count(make_pair(i, j)) || bridges.count(make_pair(j, i)))
			continue;
		if (C[j] == 0)
		{
			C[j] = C[i];
			dfs(j);
		}
	}
}
vector<int>kaim[202020];
int tev[202020][30];
int dep[202020];
int suma[202020];
void dfs1(int i, int p)
{
	dep[i] = dep[p] + 1;
	tev[i][0] = p;
	for (int t = 1; t < 30; t++)
		tev[i][t] = tev[tev[i][t - 1]][t - 1];
	for (int j : kaim[i])
	{
		if (j == p)
			continue;
		dfs1(j, i);
	}
}
void dfs2(int i, int p)
{
	for (int j : kaim[i])
	{
		if (j == p)
			continue;
		dfs2(j, i);
		suma[i] += suma[j];
	}
}
void dfs3(int i, int p)
{
	if (i != p)
		suma[i] += suma[p];
	for (int j : kaim[i])
	{
		if (j == p)
			continue;
		dfs3(j, i);
	}
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])
		swap(a, b);
	for (int t = 29; t >= 0; t--)
		if (dep[tev[a][t]] >= dep[b])
			a = tev[a][t];
	for (int t = 29; t >= 0; t--)
		if (tev[a][t] != tev[b][t])
		{
			a = tev[a][t];
			b = tev[b][t];
		}
	while (a != b)
	{
		a = tev[a][0];
		b = tev[b][0];
	}
	return a;
}
int main()
{
	clock_t pradzia = clock();
	ios_base::sync_with_stdio(false);
	int N, M, Q;
	cin >> N >> M >> Q;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		G[ {a, b}]++;
	}
	vector<int>roots;
	for (int i = 1; i <= N; i++)
		if (!buvau[i])
		{
			dfs(1, 1);
			roots.push_back(i);
		}
	for (int i = 1; i <= N; i++)
		if (C[i] == 0)
		{
			dfs(i);
		}
	for (int &c : roots)
		c = C[c];
	for (pair<int, int>a : bridges)
	{
		kaim[C[a.first]].push_back(C[a.second]);
		kaim[C[a.second]].push_back(C[a.first]);
	}
	for (int root : roots)
	{
		dep[root] = 0;
		dfs1(root, root);
	}
	vector<pair<int, int>>XXX;
	if ((clock() - pradzia) / CLOCKS_PER_SEC >= 2.0)
		exit(3);
	bool ok = true;
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		a = C[a];
		b = C[b];
		if (a == b)
			continue;
		if (tev[a][29] != tev[b][29])
		{
			cout << "No\n";
			exit(0);
		}
		int c = lca(a, b);
		suma[b]++;
		suma[c]--;
		XXX.push_back({a, c});
	}
	if ((clock() - pradzia) / CLOCKS_PER_SEC >= 2.0)
		exit(3);
	for (int root : roots)
	{
		dfs2(root, root);
		dfs3(root, root);
	}
	for (pair<int, int>x : XXX)
	{
		int a = x.first;
		int c = x.second;
		if (suma[a] - suma[c] > 0)
		{
			ok = false;
		}
	}
	if (ok)
		cout << "Yes\n";
	else
		cout << "No\n";
}