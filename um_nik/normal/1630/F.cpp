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
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const int INF = (int)1e6;
struct Dinic {
	struct Edge {
		int v, to;
		int cap;

		Edge() : v(), to(), cap() {}
		Edge (int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap) {}
	};
	vector<Edge> ed;
	vector<vector<int>> g;
	int S, T;
	int n;
	vector<int> dist;
	vector<int> idx;

	Dinic() : ed(), g(), S(), T() {}
	Dinic(int _n, int _S, int _T) {
		n = _n;
		S = _S;
		T = _T;
		g.resize(n);
		for (int i = 0; i < n; i++)
			g[i].clear();
		ed = vector<Edge>();
	}

	void addEdge(int v, int to, int cap) {
		g[v].push_back((int)ed.size());
		ed.push_back(Edge(v, to, cap));
		g[to].push_back((int)ed.size());
		ed.push_back(Edge(to, v, 0));
	}

	bool BFS() {
		dist.resize(n);
		vector<int> q;
		for (int i = 0; i < n; i++)
			dist[i] = n;
		q.push_back(S);
		dist[S] = 0;
		for (int i = 0; i < (int)q.size(); i++) {
			int v = q[i];
			for (int id : g[v]) {
				Edge e = ed[id];
				if (e.cap <= 0) continue;
				int u = e.to;
				if (dist[u] <= dist[v] + 1) continue;
				dist[u] = dist[v] + 1;
				q.push_back(u);
			}
		}
		return dist[T] < n;
	}

	ll dfs(int v, int flow) {
		if (v == T || flow == 0) return flow;
		int res = 0;
		for (int &i = idx[v]; i < (int)g[v].size(); i++) {
			int id = g[v][i];
			Edge e = ed[id];
			int to = e.to;
			if (dist[to] != dist[v] + 1) continue;
			ll df = dfs(to, min(flow, e.cap));
			flow -= df;
			res += df;
			ed[id].cap -= df;
			ed[id ^ 1].cap += df;
			if (flow == 0) return res;
		}
		return res;
	}

	int Flow() {
		idx.resize(n);
		int res = 0;
		while(BFS()) {
			for (int i = 0; i < n; i++)
				idx[i] = 0;
			res += dfs(S, INF);
		}
		return res;
	}
} G;

const int N = 50500;
int id[N];
vector<int> d[N];
int s, t, n;
int a[N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		id[a[i]] = i;
	}
	s = 4 * n;
	t = s + 1;
	G = Dinic(4 * n + 2, s, t);
	for (int i = 0; i < n; i++) {
		G.addEdge(s, 4 * i, 1);
		G.addEdge(4 * i + 1, 4 * i + 2, 1);
		G.addEdge(4 * i + 3, t, 1);
	}
	for (int i = 0; i < n; i++)
		for (int x : d[a[i]]) {
			int v = id[x];
			if (v == -1) continue;
			G.addEdge(4 * i, 4 * v + 1, 1);
			G.addEdge(4 * i + 2, 4 * v + 3, 1);
		}
	int ans = G.Flow();
	for (int i = 0; i < n; i++)
		id[a[i]] = -1;
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		id[i] = -1;
	for (int x = 1; x < N; x++)
		for (int y = 2 * x; y < N; y += x)
			d[y].push_back(x);

	int z;
	scanf("%d", &z);
	while(z--) solve();

	return 0;
}