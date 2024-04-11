#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
map<pair<int, int>, int> edge_idx;
int parent[300005];
int gidx[300005];
set<int, greater<>> elem[300005];

int idx(int a, int b)
{
	return edge_idx.insert({ {a, b}, (int)edge_idx.size() + 1 }).first->second;
}

int getparent(int t)
{
	if (parent[t] == 0) parent[t] = t;
	return t == parent[t] ? t : parent[t] = getparent(parent[t]);
}

void merge(int a, int b)
{
	parent[getparent(a)] = getparent(b);
}

map<set<int, greater<>>, int> dual_idx;
vector<int> dual_graph[100005];
pair<int, int> diag[100005];
int ans[100005];
bool block[100005];
int f1, f2;
int childcnt[100005];

void dfs(int t, int p)
{
	childcnt[t] = 1;

	for (int nxt : dual_graph[t])
	{
		if (nxt == p || block[nxt]) continue;
		dfs(nxt, t);
		childcnt[t] += childcnt[nxt];
	}
}

void dfs2(int t, int p, int total)
{
	for (int nxt : dual_graph[t])
	{
		if (block[nxt] || nxt == p) continue;

		if (childcnt[nxt] > total / 2)
		{
			dfs2(nxt, t, total);
			return;
		}
	}

	f1 = t;
}

void recur(int t, int col)
{
	dfs(t, -1);
	dfs2(t, -1, childcnt[t]);

	ans[f1] = col;
	block[f1] = true;
	for (int nxt : dual_graph[f1])
	{
		if (block[nxt]) continue;
		recur(nxt, col + 1);
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		graph[i].push_back(i + 1);
	}
	graph[n].push_back(1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		//a = 1; b = i + 3;
		graph[a].push_back(b);
		graph[b].push_back(a);

		diag[i] = { a, b };
	}

	for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

	for (int i = 1; i <= n; i++)
	{
		for (int j : graph[i])
		{
			int k = (lower_bound(graph[j].begin(), graph[j].end(), i) - graph[j].begin() + graph[j].size() - 1) % graph[j].size();
			merge(idx(i, j), idx(j, graph[j][k]));
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j : graph[i])
		{
			int k = idx(i, j);
			elem[getparent(k)].insert(i);
			elem[getparent(k)].insert(j);
		}
	}

	for (int i = 1; i <= edge_idx.size(); i++)
	{
		if (elem[i].empty()) continue;
		dual_idx.emplace(elem[i], 0);
	}

	{
		int f = 0;
		for (auto &&e : dual_idx)
		{
			e.second = f++;
		}
	}

	for (int i = 1; i <= edge_idx.size(); i++)
	{
		if (elem[i].empty()) continue;
		gidx[i] = dual_idx[elem[i]];
	}

	for (int i = 0; i < m; i++)
	{
		int a = idx(diag[i].first, diag[i].second);
		int b = idx(diag[i].second, diag[i].first);

		dual_graph[gidx[getparent(a)]].push_back(gidx[getparent(b)]);
		dual_graph[gidx[getparent(b)]].push_back(gidx[getparent(a)]);
	}

	recur(0, 1);
	for (int i = 0; i < dual_idx.size(); i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
}