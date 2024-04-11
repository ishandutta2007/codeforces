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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = (ll)1e18 + 33;
const int V = 101;
const int N = 100010;
int G[V][V];
int n;
int m, k;
int a[N][4];
ll c[N];
vector<pii> b[N];

struct Edge {
	int v, to;
	ll cap;

	Edge() : v(), to(), cap() {}
	Edge (int _v, int _to, ll _cap) : v(_v), to(_to), cap(_cap) {}
};
Edge ed[N];
int edSz;
vector<int> g[N];
int dist[N];
int q[N];
int topQ;
int idx[N];
int idd[N];
int S, T;

void addEdge(int v, int to, ll cap) {
	ed[edSz] = Edge(v, to, cap);
	g[v].push_back(edSz++);
	ed[edSz] = Edge(to, v, 0);
	g[to].push_back(edSz++);
}

bool BFS() {
	for (int i = 0; i <= T; i++)
		dist[i] = N;
	topQ = 0;
	dist[S] = 0;
	q[topQ++] = S;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int id : g[v]) {
			Edge e = ed[id];
			if (e.cap <= 0) continue;
			int to = e.to;
			if (dist[to] <= dist[v] + 1) continue;
			dist[to] = dist[v] + 1;
			q[topQ++] = to;
		}
	}
	return dist[T] < N;
}
ll dfs(int v, ll flow) {
	if (v == T || flow == 0) return flow;
	ll res = 0;
	for (int &i = idx[v]; i < (int)g[v].size(); i++) {
		int id = g[v][i];
		Edge e = ed[id];
		int to = e.to;
		if (dist[to] != dist[v] + 1) continue;
		ll df = dfs(to, min(flow, e.cap));
		res += df;
		flow -= df;
		ed[id].cap -= df;
		ed[id ^ 1].cap += df;
		if (flow == 0) return res;
	}
	return res;
}

ll Flow() {
	ll res = 0;
	while(BFS()) {
		for (int i = 0; i <= T; i++)
			idx[i] = 0;
		res += dfs(S, INF);
	}
	return res;
}

void readGraph() {
	int e;
	scanf("%d%d", &n, &e);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = (i == j ? 0 : N);
	while(e--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		if (v != u)
			G[v][u] = G[u][v] = 1;
	}
	for (int z = 0; z < n; z++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				G[x][y] = min(G[x][y], G[x][z] + G[z][y]);
}

ll read() {
	readGraph();
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		a[i][0]--;
	}
	for (int i = 0; i < k; i++) {
		int v, x, y;
		scanf("%d%d%d", &v, &x, &y);
		v--;
		b[v].push_back(mp(x, y));
	}
	for (int v = 0; v < V; v++) {
		sort(b[v].begin(), b[v].end());
		for (int i = 1; i < (int)b[v].size(); i++)
			b[v][i].second = max(b[v][i].second, b[v][i - 1].second);
	}
	for (int i = 0; i < n; i++) {
		c[i] = -INF;
		for (int v = 0; v < V; v++) {
			if (b[v].empty()) continue;
			if (G[a[i][0]][v] > a[i][2]) continue;
			int p = upper_bound(b[v].begin(), b[v].end(), mp(a[i][1] + 1, -1)) - b[v].begin();
			if (p > 0) c[i] = max(c[i], (ll)b[v][p - 1].second);
		}
		c[i] -= a[i][3];
	}
	S = 0;
	for (int i = 0; i < n; i++)
		idd[i] = -1;
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		if (idd[v] == -1) idd[v] = S++;
		if (idd[u] == -1) idd[u] = S++;
		v = idd[v];
		u = idd[u];
		addEdge(v, u, INF);
	}
	T = S + 1;
	ll ans = 0;
	for (int v = 0; v < n; v++) {
		if (idd[v] == -1) {
			ans += max(0LL, c[v]);
			continue;
		}
		if (c[v] <= 0) {
			addEdge(idd[v], T, -c[v]);
		} else {
			ans += c[v];
			addEdge(S, idd[v], c[v]);
		}
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll ans = read();
	printf("%lld\n", ans - Flow());

	return 0;
}