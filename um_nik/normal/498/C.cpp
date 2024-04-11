#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (int)1e8;
const int N = 500;
int n;
int ans;
int a[N];
set<int> p;
int m;
int b[N][2];

struct Edge
{
	int to, cap, flow;

	Edge () : to(), cap(), flow() {}
	Edge (int _to, int _cap) : to(_to), cap(_cap), flow(0) {}
};

int sz;
Edge ed[2 * N];
vector<int> g[N];
int S, T;

void fact(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i != 0) continue;
		p.insert(i);
		while (x % i == 0) x /= i;
	}
	if (x != 1)
		p.insert(x);
	return;
}

void addEdge(int v, int to, int cap)
{
	ed[sz] = Edge(to, cap);
	g[v].push_back(sz++);
	ed[sz] = Edge(v, 0);
	g[to].push_back(sz++);
	return;
}

int q[N];
int qSz;
int d[N];
bool bfs(int S, int T, int n)
{
	for (int i = 0; i < n; i++)
		d[i] = INF;
	d[S] = 0;
	qSz = 1;
	q[0] = S;
	for (int k = 0; k < qSz; k++)
	{
		int v = q[k];
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			Edge e = ed[g[v][i]];
			if (e.flow == e.cap) continue;
			int to = e.to;
			if (d[to] <= d[v] + 1) continue;
			d[to] = d[v] + 1;
			q[qSz++] = to;
		}
	}
	return (d[T] < INF);
}

int idx[N];
int dfs(int v, int T, int pushFlow)
{
	int res = 0;
	if (v == T || pushFlow == 0) return pushFlow;
	for (; idx[v] < (int)g[v].size(); idx[v]++)
	{
		int id = g[v][idx[v]];
		Edge e = ed[id];
		int to = e.to;
		if (d[to] != d[v] + 1) continue;
		int deltaFlow = dfs(to, T, min(pushFlow, e.cap - e.flow));
		pushFlow -= deltaFlow;
		res += deltaFlow;
		ed[id].flow += deltaFlow;
		ed[id ^ 1].flow -= deltaFlow;
		if (pushFlow == 0) break;
	}
	return res;
}

int flow(int S, int T, int n)
{
	int res = 0;
	while (bfs(S, T, n))
	{
		for (int i = 0; i < n; i++)
			idx[i] = 0;
		res += dfs(S, T, INF);
	}
	return res;
}

int solve(int q)
{
	for (int i = 0; i < n + 2; i++)
		g[i].clear();
	sz = 0;
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		int t = a[i];
		while (t % q == 0)
		{
			t /= q;
			c++;
		}
		if (i % 2 == 0)
			addEdge(S, i, c);
		else
			addEdge(i, T, c);
	}
	for (int i = 0; i < m; i++)
		addEdge(b[i][0], b[i][1], INF);
	return flow(S, T, n + 2);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		fact(a[i]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &b[i][j]);
			b[i][j]--;
		}
	for (int i = 0; i < m; i++)
	{
		if (b[i][0] % 2 == 1)
			swap(b[i][0], b[i][1]);
	}
	S = n;
	T = n + 1;
	for (auto it = p.begin(); it != p.end(); it++)
		ans += solve(*it);
	printf("%d\n", ans);

	return 0;
}