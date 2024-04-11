#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e8;

struct Edge
{
	int v, to;
	int cap, flow;
	int id;

	Edge() : v(), to(), cap(), flow(), id(-1) {}
	Edge (int _v, int _to, int _cap, int _id) : v(_v), to(_to), cap(_cap), flow(0), id(_id) {}
};

const int V = 111;
const int E = 10101;
vector<int> g[V];
Edge ed[E];
int edSz;
int n, m, S, T;
int dist[V];
int q[V];
int topQ;
int idx[V];
int ans[E];
bool inCut[E];
int G[V][V];
int par[V];

void addEdge(int v, int u, int cap, int id) {
	ed[edSz] = Edge(v, u, cap, id);
	g[v].push_back(edSz++);
	ed[edSz] = Edge(u, v, 0, -1);
	g[u].push_back(edSz++);
}

bool BFS() {
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[S] = 0;
	topQ = 0;
	q[topQ++] = S;
	for (int k = 0; k < topQ; k++) {
		int v = q[k];
		for (int id : g[v]) {
			Edge e = ed[id];
			if (e.cap == e.flow) continue;
			int to = e.to;
			if (dist[to] <= dist[v] + 1) continue;
			dist[to] = dist[v] + 1;
			q[topQ++] = to;
		}
	}
	return dist[T] < INF;
}
int dfs(int v, int flow) {
	if (v == T || flow == 0) return flow;
	int res = 0;
	for (int &i = idx[v]; i < (int)g[v].size(); i++) {
		int id = g[v][i];
		Edge e = ed[id];
		int to = e.to;
		if (dist[to] != dist[v] + 1) continue;
		int df = dfs(to, min(flow, e.cap - e.flow));
		res += df;
		flow -= df;
		ed[id].flow += df;
		ed[id ^ 1].flow -= df;
		if (flow == 0) return res;
	}
	return res;
}

int Flow() {
	int res = 0;
	while(BFS()) {
		for (int i = 0; i < n; i++)
			idx[i] = 0;
		res += dfs(S, INF);
	}
	return res;
}

void makeCycle(int U, int W) {
	//printf("%d %d\n", U, W);
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[W] = 0;
	topQ = 0;
	q[topQ++] = W;
	for (int k = 0; k < topQ; k++) {
		int v = q[k];
		//printf("%d\n", v);
		for (int u = 0; u < n; u++) {
			if (G[v][u] == -1) continue;
			if (dist[u] <= dist[v] + 1) continue;
			dist[u] = dist[v] + 1;
			par[u] = v;
			q[topQ++] = u;
		}
	}
	if (dist[U] == INF) throw;
	ans[G[U][W]]++;
	while(U != W) {
		int v = par[U];
		ans[G[v][U]]++;
		U = v;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &S, &T);
	S--;T--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = -1;
	for (int i = 0; i < m; i++) {
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c);
		v--;u--;
		if (c == 0)
			addEdge(v, u, INF, i);
		else {
			G[v][u] = i;
			addEdge(v, u, 1, i);
			addEdge(u, v, INF, -1);
		}
	}
	int F = Flow();
	printf("%d\n", F);

	for (int v = 0; v < n; v++) {
		if (dist[v] == INF) continue;
		for (int id : g[v]) {
			Edge e = ed[id];
			if (e.id == -1) continue;
			int u = e.to;
			if (dist[u] < INF) continue;
			if (e.cap != 1) throw;
			if (e.flow != 1) throw;
			inCut[e.id] = 1;
		}
	}

	G[T][S] = E - 1;
	
	for (int v = 0; v < n; v++)
		for (int u = 0; u < n; u++) {
			if (G[v][u] == -1) continue;
			if (v == T && u == S) continue;
			makeCycle(v, u);
		}

	for (int i = 0; i < m; i++) {
		if (inCut[i])
			printf("%d %d\n", ans[i], ans[i]);
		else
			printf("%d %d\n", ans[i], ans[i] + 1);
	}

	return 0;
}