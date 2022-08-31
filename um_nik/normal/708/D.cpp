#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 110;
const int E = 20000;
const int INF = (int)5e8 + 10;

struct Edge
{
	int v, to;
	int flow, cap, cost;

	Edge() : v(), to(), flow(), cap(), cost() {}
	Edge (int _v, int _to, int _cap, int _cost) : v(_v), to(_to), flow(0), cap(_cap), cost(_cost) {}
};
Edge ed[E];
int edSz;
int S, T;
int n;
int ans = 0;
int fl[N];
int dist[N];
int par[N];

void addEdge(int v, int to, int cap, int cost)
{
	ed[edSz++] = Edge(v, to, cap, cost);
	ed[edSz++] = Edge(to, v, 0, -cost);
}

void read()
{
	int m;
	scanf("%d%d", &n, &m);
	S = n;
	T = n + 1;
	while(m--)
	{
		int v, u, c, f;
		scanf("%d%d%d%d", &v, &u, &c, &f);
		v--;u--;
		fl[v] -= f;
		fl[u] += f;
		if (c < f)
		{
			ans += f - c;
			addEdge(u, v, f - c, 0);
			addEdge(u, v, c, 1);
			addEdge(v, u, INF, 2);
		}
		else
		{
			addEdge(u, v, f, 1);
			addEdge(v, u, c - f, 1);
			addEdge(v, u, INF, 2);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (fl[i] > 0)
			addEdge(S, i, fl[i], 0);
		else
			addEdge(i, T, -fl[i], 0);
	}
	addEdge(n - 1, 0, INF, 0);
	n += 2;
	return;
}

bool FB()
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[S] = 0;
	bool ch = true;
	while(ch)
	{
		ch = false;
		for (int i = 0; i < edSz; i++)
		{
			Edge e = ed[i];
			if (e.flow == e.cap) continue;
			int v = e.v;
			if (dist[v] == INF) continue;
			int u = e.to;
			if (dist[u] <= dist[v] + e.cost) continue;
			dist[u] = dist[v] + e.cost;
			par[u] = i;
			ch = true;
		}
	}
	return dist[T] != INF;
}

int MCMF()
{
	int res = 0;
	while(FB())
	{
		int flow = INF;
		int v = T;
		while(v != S)
		{
			Edge e = ed[par[v]];
			flow = min(flow, e.cap - e.flow);
			v = e.v;
		}
		v = T;
		while(v != S)
		{
			int id = par[v];
			ed[id].flow += flow;
			ed[id ^ 1].flow -= flow;
			v = ed[id].v;
		}
		res += flow * dist[T];
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	ans += MCMF();
	printf("%d\n", ans);

	return 0;
}