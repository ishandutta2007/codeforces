#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int N = 300;
const int P = 30000;
const int INF = (int)1e8;
bool p[P];
int n;
int a[N];
int S, T;
vector<int> g[N];

struct Edge
{
	int v, to, cap, flow;

	Edge () : v(), to(), cap(), flow() {}
	Edge (int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap), flow(0) {}
};

Edge ed[2 * N * N];
int edSz;

void init()
{
	for (int i = 2; i < P; i++)
		p[i] = 1;
	for (int i = 2; i < P; i++)
	{
		if (!p[i]) continue;
		for (int j = 2 * i; j < P; j += i)
			p[j] = 0;
	}
	return;
}

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	S = n;
	T = n + 1;
	return;
}

void addEdge(int v, int to, int cap)
{
	ed[edSz] = Edge(v, to, cap);
	g[v].push_back(edSz++);
	ed[edSz] = Edge(to, v, 0);
	g[to].push_back(edSz++);
	return;
}

void createGraph()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (!p[a[i] + a[j]]) continue;
			if (a[i] & 1) continue;
			addEdge(i, j, 1);
		}
	for (int i = 0; i < n; i++)
	{
		if (a[i] & 1)
			addEdge(i, T, 2);
		else
			addEdge(S, i, 2);
	}
	n += 2;
	return;
}

int dist[N];
int q[N];
int qSz;
bool bfs()
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[S] = 0;
	qSz = 1;
	q[0] = S;
	for (int k = 0; k < qSz; k++)
	{
		int v = q[k];
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			Edge e = ed[g[v][i]];
			if (e.cap == e.flow) continue;
			int to = e.to;
			if (dist[to] <= dist[v] + 1) continue;
			dist[to] = dist[v] + 1;
			q[qSz++] = to;
		}
	}
	return (dist[T] != INF);
}

int idx[N];
int dfs(int v, int pushFlow)
{
	if (v == T || pushFlow == 0) return pushFlow;
	int res = 0;
	for (; idx[v] < (int)g[v].size(); idx[v]++)
	{
		int id = g[v][idx[v]];
		Edge e = ed[id];
		int to = e.to;
		if (dist[to] != dist[v] + 1)
			continue;
		int deltaFlow = dfs(to, min(pushFlow, e.cap - e.flow));
		res += deltaFlow;
		pushFlow -= deltaFlow;
		ed[id].flow += deltaFlow;
		ed[id ^ 1].flow -= deltaFlow;
		if (pushFlow == 0) return res;
	}
	return res;
}

int getFlow()
{
	int ans = 0;
	while(bfs())
	{
		for (int i = 0; i < n; i++)
			idx[i] = 0;
		ans += dfs(S, INF);
	}
	return ans;
}

vector<int> ne[N];
vector<int> ans[N];
bool used[N];
void dfsAns(int v, int cnt)
{
	used[v] = 1;
	ans[cnt].push_back(v + 1);
	for (int i = 0; i < (int)ne[v].size(); i++)
	{
		int to = ne[v][i];
		if (!used[to]) dfsAns(to, cnt);
	}
	return;
}

void printAns()
{
	n -= 2;
	for (int i = 0; i < n; i++)
		ne[i].clear();
	for (int i = 0; i < edSz; i++)
	{
		Edge e = ed[i];
		if (e.cap != 1) continue;
		if (e.flow != 1) continue;
		int v = e.v;
		int u = e.to;
		ne[v].push_back(u);
		ne[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		used[i] = 0;
	int sz = 0;
	for (int i = 0; i < n; i++)
		ans[i].clear();
	for (int i = 0; i < n; i++)
	{
		if (used[i]) continue;
		dfsAns(i, sz);
		sz++;
	}
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
	{
		int t = (int)ans[i].size();
		printf("%d ", t);
		for (int j = 0; j < t; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}

	return;
}

int main()
{
	init();
	read();
	createGraph();
	int fl = getFlow();
//	printf("%d\n", fl);
	if (fl != n - 2)
	{
		printf("Impossible\n");
		return 0;
	}
	printAns();

	return 0;
}