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

const int N = 200200;
const int K = 5;
const int M = 122;
const int S = 10100;
int n, k, m;
int pp[M][K];
int t[M][M];
int toId[S];
int a[N];
bool g[M];
int q[M];
int topQ;
vector<int> b[N];
vector<int> cur;

void precalc() {
	for (int i = 0; i < k; i++)
		pp[0][i] = i;
	m = 1;
	while(true) {
		for (int i = 0; i < k; i++)
			pp[m][i] = pp[m - 1][i];
		if (!next_permutation(pp[m], pp[m] + k)) break;
		m++;
	}
	for (int i = 0; i < S; i++)
		toId[i] = -1;
	for (int i = 0; i < m; i++) {
		int id = 0;
		for (int j = 0; j < k; j++) {
			id = id * k + pp[i][j];
		}
		toId[id] = i;
	}
	int qq[K];
	for (int v = 0; v < m; v++)
		for (int u = 0; u < m; u++) {
			for (int i = 0; i < k; i++)
				qq[i] = pp[v][pp[u][i]];
			int id = 0;
			for (int i = 0; i < k; i++)
				id = id * k + qq[i];
			id = toId[id];
			if (id == -1) throw;
			t[v][u] = id;
		}
}

bool tryAdd(int id) {
	if (g[id]) return false;
	cur.push_back(id);
	for (int i = 0; i < m; i++)
		g[i] = 0;
	g[0] = 1;
	topQ = 0;
	q[topQ++] = 0;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int x : cur) {
			int u = t[v][x];
			if (!g[u]) {
				g[u] = 1;
				q[topQ++] = u;
			}
		}
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	precalc();
	for (int i = 0; i < n; i++) {
		int id = 0;
		for (int j = 0; j < k; j++) {
			int x;
			scanf("%d", &x);
			x--;
			id = id * k + x;
		}
		id = toId[id];
		if (id == -1) throw;
		a[i] = id;
	}

	ll ans = 0;
	for (int v = n - 1; v >= 0; v--) {
		cur.clear();
		for (int i = 0; i < m; i++)
			g[i] = 0;
		g[0] = 1;
		int curSz = 1;
		int lst = v;
		if (tryAdd(a[v])) {
			b[v].push_back(v);
			ans += curSz * (v - lst);
			curSz = topQ;
			lst = v;
//			eprintf("%d\n", curSz);
		}
		for (int u : b[v + 1]) {
			if (tryAdd(a[u])) {
				b[v].push_back(u);
				ans += curSz * (u - lst);
				curSz = topQ;
				lst = u;
//				eprintf("%d\n", curSz);
			}
		}
		ans += curSz * (n - lst);
	}
	printf("%lld\n", ans);

	return 0;
}