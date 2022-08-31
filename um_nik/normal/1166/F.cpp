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

const int N = 100100;
int par[5 * N];
vector<int> a[5 * N];
map<pii, int> mapchik;
int n, m, k, q;
set<int> compsNear[N];
vector<int> g[N];

int getV(int v, int c) {
	pii t = mp(v, c);
	if (mapchik.count(t)) return mapchik[t];
	mapchik[t] = k;
	return k++;
}

void changeNeighbours(int v, int old, int nw) {
	for (int u : g[v]) {
		if (compsNear[u].count(old))
			compsNear[u].erase(old);
		compsNear[u].insert(nw);
	}
}

void unite(int v, int u) {
	v = par[v];
	u = par[u];
	if (v == u) return;
	if ((int)a[v].size() < (int)a[u].size()) swap(v, u);
	for (int w : a[u]) {
		par[w] = v;
		a[v].push_back(w);
		if (w < n)
			changeNeighbours(w, u, v);
	}
}

void addEdge() {
	int v, u, c;
	scanf("%d%d%d", &v, &u, &c);
	v--;u--;
	int V = getV(v, c), U = getV(u, c);
	unite(v, U);
	unite(u, V);
	g[v].push_back(u);
	g[u].push_back(v);
	compsNear[v].insert(par[u]);
	compsNear[u].insert(par[v]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < 5 * N; i++) {
		par[i] = i;
		a[i].push_back(i);
	}
	for (int v = 0; v < n; v++) {
		g[v].push_back(v);
		compsNear[v].insert(v);
	}
	k = n;
	while(m--) {
		addEdge();
	}
	while(q--) {
		char c;
		scanf(" %c", &c);
		if (c == '+') {
			addEdge();
		} else {
			int v, u;
			scanf("%d%d", &v, &u);
			v--;u--;
			v = par[v];
			if (compsNear[u].count(v))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;
}