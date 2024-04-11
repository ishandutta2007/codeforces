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

struct Edge {
	int v, u, w;

	Edge() : v(), u(), w() {}

	void scan() {
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
	}

	bool operator < (const Edge &e) const {
		return w < e.w;
	}
};

const int N = 100100;
int n, m, k;
int par[N];
int sz[N];
int a[N];
int S, T;
int x[N];
Edge ed[N];

int getPar(int v) {
	return par[v] == -1 ? v : par[v] = getPar(par[v]);
}
void unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	a[v] += a[u];
	par[u] = v;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int v = 0; v < n; v++) {
		par[v] = -1;
		sz[v] = 0;
		a[v] = 0;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &x[i]);
		x[i]--;
		a[x[i]] = 1;
	}
	for (int i = 0; i < m; i++)
		ed[i].scan();
	sort(ed, ed + m);
	for (int i = 0; i < m; i++) {
		unite(ed[i].v, ed[i].u);
		if (a[getPar(ed[i].v)] == k) {
			for (int j = 0; j < k; j++)
				printf("%d ", ed[i].w);
			printf("\n");
			return 0;
		}
	}
	throw;
	return 0;
}