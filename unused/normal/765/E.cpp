#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
int f1, f2;
int up[200005];

void dfs(int t, int p, int v)
{
	if (f1 < v)
	{
		f1 = v; f2 = t;
	}

	for (int n : graph[t])
	{
		if (n == p) continue;
		dfs(n, t, v + 1);
	}
}

vector<int> centers;
constexpr int INF = (int)1e9 + 1;

void dfs2(int t, int p, int v)
{
	if (v == f1 / 2)
	{
		centers.push_back(t);
	}
	else if (v == (f1 + 1) / 2)
	{
		centers.push_back(t);
	}
	else if (v > (f1 + 1) / 2) return;

	for (int n : graph[t])
	{
		if (n == p) continue;
		dfs2(n, t, v + 1);
	}
}

void dfs3(int t, int p)
{
	unordered_set<int> l;

	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		dfs3(nxt, t);
		l.insert(up[nxt]);
	}

	if (p == -1)
	{
		up[t] = 0;

		if (l.size() > 2)
		{
			up[t] = INF;
		}
		else for (int x : l) up[t] = min(INF, up[t] + x);
	}
	else
	{
		if (l.size() > 1)
		{
			up[t] = INF;
		}
		else up[t] = min(INF, l.empty() ? 1 : *l.begin() + 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	f1 = -1;
	dfs(1, -1, 0);
	f1 = -1;
	dfs(f2, -1, 0);
	dfs2(f2, -1, 0);
	f2 = INF;
	shuffle(centers.begin(), centers.end(), mt19937{});
	clock_t start = clock();
	for (int x : centers)
	{
		if (x == 0) continue;
		dfs3(x, -1);
		while (up[x] % 2 == 0) up[x] /= 2;
		f2 = min(f2, up[x]);
		if (clock() - start >= 1.7 * CLOCKS_PER_SEC) break;
	}
	if (f2 == INF) f2 = -1;
	printf("%d\n", f2);
}