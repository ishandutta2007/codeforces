#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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

struct Edge {
	int v, to, cap;
	ll cost;

	Edge() : v(), to(), cap(), cost() {}
	Edge(int _v, int _to, int _cap, ll _cost) : v(_v), to(_to), cap(_cap), cost(_cost) {}
};
const int N = 222;
const int V = N * N + 3;
const int E = N * N * 9 + 3;
vector<int> g[V];
Edge ed[E];
int edSz;
int S, T;

void addEdge2(int v, int to, int cap, ll cost) {
	ed[edSz] = Edge(v, to, cap, cost);
	g[v].push_back(edSz++);
}
void addEdge(int v, int to, int cap, ll cost) {
	addEdge2(v, to, cap, cost);
	addEdge2(to, v, 0, -cost);
}


ll a[N][N];
ll b[V];
int n;

bool good[V];
bool used[V];
int par[V];

int bV, bU;
int bstVal;

void dfs1(int v, int st) {
	used[v] = 1;
	if (good[v] && b[v] - b[st] < bstVal) {
		bstVal = b[v] - b[st];
		bV = st;
		bU = v;
	}
	for (int id : g[v]) {
		Edge e = ed[id];
		if (e.cap <= 0) continue;
		int to = e.to;
		if (used[to]) continue;
		par[to] = id;
		dfs1(to, st);
	}
}

ll MCMF() {
	ll ans = 0;
	while(true) {
		vector<pli> ord;
		for (int i = 0; i < n; i++) {
			used[i] = false;
			if (good[i]) ord.push_back(mp(b[i], i));
		}
		sort(all(ord));
		reverse(all(ord));
		bV = bU = -1;
		bstVal = 0;
		for (auto t : ord) {
			int v = t.second;
			if (used[v]) continue;
			dfs1(v, v);
		}
		if (bstVal == 0) return ans;
		//eprintf("%d %d\n", bV, bU);
		ans += bstVal;
		int v = bU;
		while(v != bV) {
			int id = par[v];
			ed[id].cap--;
			ed[id ^ 1].cap++;
			v = ed[id].v;
		}
		good[bV] = good[bU] = false;
	}
	return ans;
}

void read() {
	/*
	n = 200;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
			if (i != 0 && i != n - 1 && j != 0 && j != n - 1) continue;
			a[i][j] = myRand(1e9) + 1;
		}
	}
	*/
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%lld", &a[i][j]);
		}
	
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();

	S = n * n;
	T = S + 1;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j] > 0) {
//				addEdge(S, i * n + j, 1, a[i][j]);
//				addEdge(i * n + j, T, 1, -a[i][j]);
				b[i * n + j] = a[i][j];
				good[i * n + j] = 1;
			}
		}
	ll ans = 0;
	for (int x = 0; x < n; x++) 
		for (int y = 0; y < n; y++) {
			if (a[x][y] == -1) continue;
			if (x + 1 < n && a[x + 1][y] != -1) {
				if (a[x][y] != 0 && a[x + 1][y] != 0) {
					ans += abs(a[x][y] - a[x + 1][y]);
				} else {
					int v = x * n + y, u = (x + 1) * n + y;
					addEdge2(v, u, 1, 0);
					addEdge2(u, v, 1, 0);
				}
			}
			if (y + 1 < n && a[x][y + 1] != -1) {
				if (a[x][y] != 0 && a[x][y + 1] != 0) {
					ans += abs(a[x][y] - a[x][y + 1]);
				} else {
					int v = x * n + y, u = x * n + y + 1;
					addEdge2(v, u, 1, 0);
					addEdge2(u, v, 1, 0);
				}
			}
		}
//	eprintf("curans = %lld\n", ans);
//	n = T + 1;
	n = n * n;
	printf("%lld\n", ans - MCMF());

	return 0;
}