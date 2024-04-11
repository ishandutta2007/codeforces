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

bool query(int v, int u) {
	printf("? %d %d\n", v, u);
	fflush(stdout);
	scanf("%d", &v);
	if (v == -1) throw;
	return v;
}

const int N = 100100;
bool used[N];
int ord[N];
int ordSz;
int col[N];
int n, m;
vector<int> g[N], rg[N];
vector<int> G[N];
int deg[N];
int q[N];
int topQ;
vector<int> comp[N];

void dfsOrd(int v) {
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfsOrd(u);
	ord[ordSz++] = v;
}
void dfsCol(int v) {
	col[v] = m;
	comp[m].push_back(v);
	for (int u : rg[v])
		if (col[u] == -1)
			dfsCol(u);
}

void myFree(int v) {
	for (int u : G[v]) {
		deg[u]--;
		if (deg[u] == 0)
			q[topQ++] = u;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		rg[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		dfsOrd(i);
	}
	for (int i = 1; i <= n; i++)
		col[i] = -1;
	m = 0;
	for (int i = n - 1; i >= 0; i--) {
		int v = ord[i];
		if (col[v] != -1) continue;
		dfsCol(v);
		m++;
	}
	/*
	for (int i = 1; i <= n; i++)
		eprintf("%d ", col[i]);
	eprintf("\n");
	*/
	for (int v = 1; v <= n; v++)
		for (int u : g[v])
			if (col[v] != col[u])
				G[col[v]].push_back(col[u]);
	for (int v = 0; v < m; v++) {
		sort(G[v].begin(), G[v].end());
		G[v].resize(unique(G[v].begin(), G[v].end()) - G[v].begin());
		for (int u : G[v]) {
			//eprintf("edge %d %d\n", v, u);
			deg[u]++;
		}
	}
	for (int v = 0; v < m; v++)
		if (deg[v] == 0) {
			q[topQ++] = v;
		}
	
	int V = q[0];
	for (int i = 1; i < topQ; i++) {
		int U = q[i];
		while(!comp[V].empty() && !comp[U].empty()) {
			int v = comp[V].back(), u = comp[U].back();
			if (query(v, u))
				comp[U].pop_back();
			else
				comp[V].pop_back();
		}
		if (comp[V].empty()) {
			swap(V, U);
		}
		myFree(U);
	}
	printf("! %d\n", comp[V].back());

	return 0;
}