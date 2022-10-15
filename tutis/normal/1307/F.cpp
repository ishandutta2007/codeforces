/*input
6 3 1
1 2
1 4
4 3
4 5
5 6
3
30
1 2
1 3
1 4
1 5
1 6
2 1
2 3
2 4
2 5
2 6
3 1
3 2
3 4
3 5
3 6
4 1
4 2
4 3
4 5
4 6
5 1
5 2
5 3
5 4
5 6
6 1
6 2
6 3
6 4
6 5
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>adj[404040];
void edge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}
int D[404040];
int d[404040];
const int logb2 = 30;
int pa[404040][logb2];
void dfs(int i, int p)
{
	pa[i][0] = p;
	for (int t = 1; t < logb2; t++)
		pa[i][t] = pa[pa[i][t - 1]][t - 1];
	for (int j : adj[i])
	{
		if (j != p)
		{
			d[j] = d[i] + 1;
			dfs(j, i);
		}
	}
}
int lca(int a, int b)
{
	if (d[a] > d[b])
		swap(a, b);
	for (int t = logb2 - 1; t >= 0; t--)
		if (d[pa[b][t]] >= d[a])
			b = pa[b][t];
	for (int t = logb2 - 1; t >= 0; t--)
		if (pa[a][t] != pa[b][t])
		{
			a = pa[a][t];
			b = pa[b][t];
		}
	if (a != b)
		return pa[a][0];
	else
		return a;
}
int tev[404040];
int root(int i)
{
	if (i == tev[i])
		return i;
	return tev[i] = root(tev[i]);
}
void merge(int a, int b)
{
	tev[root(a)] = root(b);
}
int getpa(int a, int k)
{
	for (int t = logb2 - 1; t >= 0; t--)
	{
		if ((k & (1 << t)) != 0)
			a = pa[a][t];
	}
	return a;
}
bool f(int l, int r, int cl, int cr)
{
	if (root(l) == root(r))
		return true;
	if (cl == 0 && cr == 0)
		return false;
	int v = lca(l, r);
	int k1 = min(cl, d[l] - d[v]);
	int k2 = min(cr, d[r] - d[v]);
	if (k1 != 0)
		return f(getpa(l, k1), r, cl - k1, cr);
	if (k2 != 0)
		return f(l, getpa(r, k2), cl, cr - k2);
	if (cl != 0)
		return f(getpa(r, d[r] - d[l] - cl), r, 0, cr);
	return f(r, l, cr, cl);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, r;
	cin >> n >> k >> r;
	int timer = n + 1;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		edge(u, timer);
		edge(v, timer);
		timer++;
	}
	fill_n(D, 404040, timer + 10);
	iota(tev, tev + 404040, 0);
	queue<int>Q;
	while (r--)
	{
		int a;
		cin >> a;
		Q.push(a);
		D[a] = 0;
	}
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		for (int b : adj[a])
		{
			if (D[b] > D[a] + 1)
			{
				D[b] = D[a] + 1;
				Q.push(b);
			}
			if (D[b] <= k && D[a] <= k - 1)
				merge(a, b);
			if (D[b] <= k - 1 && D[a] <= k)
				merge(a, b);
		}
	}
	dfs(1, 1);
	int v;
	cin >> v;
	while (v--)
	{
		int a, b;
		cin >> a >> b;
		if (d[a] + d[b] - 2 * d[lca(a, b)] <= k * 2)
			cout << "YES\n";
		else if (f(a, b, k, k))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}