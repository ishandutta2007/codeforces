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

const int INF = (int)1e9 + 33;
const int V = 101;
const int N = 1010;
int G[V][V];
int n;
int m, k;
ll C1, C2;
int a[N][3];
int b[N][2];
bool g[N][N];
int mt[N];
bool used[N];

void readGraph() {
	int e;
	scanf("%d%d", &n, &e);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = (i == j ? 0 : INF);
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

bool dfs(int x) {
	if (used[x]) return false;
	used[x] = 1;
	for (int y = 0; y < k; y++) {
		if (!g[x][y]) continue;
		if (mt[y] == -1 || dfs(mt[y])) {
			mt[y] = x;
			return true;
		}
	}
	return false;
}
int kuhn() {
	for (int i = 0; i < k; i++)
		mt[i] = -1;
	int res = 0;
	for (int i = 0; i < m; i++) {
		if (dfs(i)) {
			res++;
			for (int j = 0; j < m; j++)
				used[j] = 0;
		}
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	readGraph();
	scanf("%d%d%lld%lld", &m, &k, &C1, &C2);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		a[i][0]--;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &b[i][0], &b[i][1]);
		b[i][0]--;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++) {
			if (G[a[i][0]][b[j][0]] > a[i][2]) continue;
			if (a[i][1] < b[j][1]) continue;
			g[i][j] = 1;
		}
	printf("%lld\n", min(kuhn() * C1, m * C2));

	return 0;
}