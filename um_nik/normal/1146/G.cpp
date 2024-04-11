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

const int INF = (int)1e9;
const int N = 10100;
const int M = 100100;
struct Edge {
	int v, to, cap;

	Edge() : v(), to(), cap() {}
	Edge(int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap) {}
};
Edge ed[M];
int edSz;
vector<int> g[N];
int dist[N];
int q[N];
int topQ;
int idx[N];
int S, T;
int n, h, m;

void addEdge(int v, int to, int cap) {
	ed[edSz] = Edge(v, to, cap);
	g[v].push_back(edSz++);
	ed[edSz] = Edge(to, v, 0);
	g[to].push_back(edSz++);
}
bool BFS() {
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[S] = 0;
	topQ = 0;
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
		int df = dfs(to, min(flow, e.cap));
		flow -= df;
		res += df;
		ed[id].cap -= df;
		ed[id ^ 1].cap += df;
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

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &h, &m);
	S = n * h + m;
	T = S + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < h; j++) {
			int v = i * h + j;
			addEdge(S, v, 2 * j + 1);
			if (j > 0)
				addEdge(v, v - 1, INF);
		}
	for (int i = 0; i < m; i++) {
		int l, r, x, c;
		scanf("%d%d%d%d", &l, &r, &x, &c);
		if (x >= h) continue;
		addEdge(n * h + i, T, c);
		l--;
		for (int j = l; j < r; j++) {
			int v = j * h + x;
			addEdge(v, n * h + i, INF);
		}
	}
	int ans = n * h * h;
	n = T + 1;
	printf("%d\n", ans - Flow());

	return 0;
}