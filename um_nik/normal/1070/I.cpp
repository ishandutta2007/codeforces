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
#include <chrono>
#include <random>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 101010;

const int N = 15000;
struct Edge {
	int v, to, cap, flow;

	Edge() : v(), to(), cap(), flow() {}
	Edge(int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap), flow(0) {}
};
Edge ed[N];
int edSz;
vector<int> g[N];
int S, T;
int n, m;
int ans[N];
vector<int> edForV[N];
int deg[N];
int dist[N];
int q[N];
int topQ;
int idx[N];

void addEdge(int v, int u, int cap) {
	//cerr << "addEdge " << v << " " << u << " " << cap << endl;
	ed[edSz] = Edge(v, u, cap);
	g[v].push_back(edSz++);
	ed[edSz] = Edge(u, v, 0);
	g[u].push_back(edSz++);
}

void clear() {
	edSz = 0;
	for (int i = 0; i <= T; i++)
		g[i].clear();
	for (int i = 0; i < n; i++) {
		edForV[i].clear();
		deg[i] = 0;
	}
}

bool BFS() {
	for (int i = 0; i <= T; i++)
		dist[i] = INF;
	dist[S] = 0;
	topQ = 0;
	q[topQ++] = S;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
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
		for (int i = 0; i <= T; i++)
			idx[i] = 0;
		res += dfs(S, INF);
	}
	return res;
}

void printAns() {
	for (int i = 0; i < edSz; i++) {
		//cerr << ed[i].v << " " << ed[i].to << " " << ed[i].flow << endl;
		if (ed[i].flow <= 0) continue;
		int v = ed[i].v, u = ed[i].to;
		if (v >= n || u < n || u >= n + m) continue;
		//cerr << v << " " << u << endl;
		edForV[v].push_back(u - n);
	}
	for (int i = 0; i < m; i++)
		ans[i] = 0;
	int id = 1;
	for (int v = 0; v < n; v++) {
		//cerr << (int)edForV[v].size() << endl;
		for (int i = 0; i < (int)edForV[v].size(); i++) {
			ans[edForV[v][i]] = id;
			if (i & 1) id++;
		}
	}
	for (int i = 0; i < m; i++)
		if (ans[i])
			printf("%d ", ans[i]);
		else
			printf("%d ", id++);
	printf("\n");
}

void solve() {
	clear();
	int k;
	scanf("%d%d%d", &n, &m, &k);
	S = n + m;
	T = S + 1;
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		deg[v]++;
		deg[u]++;
		addEdge(v, n + i, 1);
		addEdge(u, n + i, 1);
		addEdge(n + i, T, 1);
	}
	bool bad = false;
	int wantFlow = 0;
	for (int i = 0; !bad && i < n; i++) {
		if (deg[i] > 2 * k) bad = true;
		if (deg[i] > k) addEdge(S, i, 2 * (deg[i] - k));
		wantFlow += max(0, 2 * (deg[i] - k));
	}
	if (bad || Flow() != wantFlow) {
		for (int i = 0; i < m; i++)
			printf("0 ");
		printf("\n");
		return;
	}
	printAns();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}