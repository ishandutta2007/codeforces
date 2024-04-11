/*input
7 1
1 1 3 3 4 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct DSU
{
	vector<int>pa;
	DSU(int n = 1)
	{
		pa = vector<int>(n + 3, -1);
	}
	int root(int i)
	{
		if (pa[i] < 0)
			return i;
		return pa[i] = root(pa[i]);
	}
	int size(int i)
	{
		return -pa[root(i)];
	}
	int merge(int a, int b)
	{
		if (a < 0 || b < 0)
			return 0;
		a = root(a);
		b = root(b);
		if (a == b)
			return a;
		if (pa[a] < pa[b])
			swap(a, b);
		pa[b] += pa[a];
		pa[a] = b;
		return b;
	}
};
int n, k;
vector<int>adj[1000002];
int fr[1000002];
int to[1000002];
int d[1000002];
int parr[1000002];
int timer = 0;
vector<int>DFS;
void dfs(int i)
{
	if (DFS.size() < k)
		parr[i] = 1;
	else
		parr[i] = DFS[DFS.size() - k];
	DFS.push_back(i);
	fr[i] = to[i] = timer++;
	for (int j : adj[i])
	{
		d[j] = d[i] + 1;
		dfs(j);
		to[i] = max(to[i], to[j]);
	}
	DFS.pop_back();
}
DSU dsu(1000002);
int X[1000002];
void dfs1(int i)
{
	X[i] = -1;
	if (adj[i].empty())
		X[i] = i;
	for (int j : adj[i])
	{
		dfs1(j);
		if (X[i] == -1)
		{
			X[i] = X[j];
			if (X[i] != -1 && d[X[i]] - d[i] > k)
				X[i] = -1;
			continue;
		}
		if (X[j] != -1)
		{
			if (d[X[j]] - d[i] <= k)
			{
				dsu.merge(X[i], X[j]);
			}
			if (d[X[j]] < d[X[i]])
				X[i] = X[j];
		}
	}
	if (X[i] != -1 && d[X[i]] - d[i] > k)
		X[i] = -1;
}
vector<int>lygy[1000009];
struct SegTree
{
	int l, r;
	int maxi = -1;
	SegTree *left, *right;
	SegTree(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new SegTree(l, (l + r) / 2);
			right = new SegTree((l + r) / 2 + 1, r);
		}
	}
	void set(int i, int w)
	{
		if (!(l <= i && i <= r))
			return;
		if (l == r)
		{
			maxi = w;
			return;
		}
		left->set(i, w);
		right->set(i, w);
		maxi = max(left->maxi, right->maxi);
	}
	int get(int a, int b)
	{
		if (a <= l && r <= b)
			return maxi;
		if (b < l || r < a)
			return -1;
		return max(left->get(a, b), right->get(a, b));
	}
};
int par(int a, int k)
{
	return parr[a];
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	dfs(1);
	dfs1(1);
	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 0)
			lygy[d[i]].push_back(i);
	SegTree XXX(0, n + 5);
	vector<int>visi[n + 4];
	int atsak = -1;
	for (int dep = n + 1; dep >= 0; dep--)
	{
		for (int i : lygy[dep])
		{
			visi[dsu.root(i)].push_back(i);
			if (dsu.size(i) == visi[dsu.root(i)].size())
			{
				int ans = 0;
				for (int j : visi[dsu.root(i)])
				{
					XXX.set(fr[j], -1);
				}
				for (int j : visi[dsu.root(i)])
				{
					int c = par(j, k);
					ans = max(ans, XXX.get(fr[c], to[c]));
				}
				ans += visi[dsu.root(i)].size();
				atsak = max(atsak, ans);
				for (int j : visi[dsu.root(i)])
				{
					XXX.set(fr[j], ans);
				}
			}
		}
	}
	cout << atsak << "\n";
}