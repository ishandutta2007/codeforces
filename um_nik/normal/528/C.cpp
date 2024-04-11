#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = (int)4e5 + 100;
int n, m;
vector<int> g[N];
int deg[N];
bool used[2 * N];
int ed[2 * N][2];
int sz;
int idx[N];
vector<int> ans;

void addEdge(int v, int u)
{
	ed[sz][0] = v;
	ed[sz][1] = u;
	g[v].push_back(sz);
	sz++;
	return;
}

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		addEdge(x, y);
		addEdge(y, x);
		deg[x]++;
		deg[y]++;
	}
	int t = -1;
	for (int v = 1; v <= n; v++)
	{
		if (deg[v] % 2 == 0) continue;
		if (t == -1)
			t = v;
		else
		{
			addEdge(t, v);
			addEdge(v, t);
			t = -1;
			m++;
		}
	}
	if (m % 2 == 1)
	{
		addEdge(1, 1);
		addEdge(1, 1);
		m++;
	}
	return;
}

void dfs(int v)
{
	while(idx[v] < (int)g[v].size())
	{
		int id = g[v][idx[v]];
		if (used[id])
		{
			idx[v]++;
			continue;
		}
		used[id] = used[id ^ 1] = 1;
		idx[v]++;
		dfs(ed[id][1]);
	}
	ans.push_back(v);
	return;
}

void solve()
{
	dfs(1);
	printf("%d\n", (int)ans.size() - 1);
	for (int i = 1; i < (int)ans.size(); i += 2)
	{
		printf("%d %d\n", ans[i], ans[i - 1]);
		printf("%d %d\n", ans[i], ans[i + 1]);
	}
	return;
}

int main()
{
	read();
	solve();


	return 0;
}