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

typedef unsigned long long ull;

const int N = 2020;
const int S = N / 64 + 3;
ull g[N][S];
int deg[N];
int n, m;
int b[N];
int ans[N];

void solve() {
	int k;
	scanf("%d%d", &n, &k);
	m = 0;
	while(m * 64 < n) m++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m; j++)
			g[i][j] = 0;
	for (int i = 0; i < n; i++)
		deg[i] = 0;
	while(k--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v][u >> 6] ^= (ull)1 << (u & 63);
		g[u][v >> 6] ^= (ull)1 << (v & 63);
		deg[v] ^= 1;
		deg[u] ^= 1;
	}
	bool bad = false;
	for (int i = 0; i < n; i++) {
		if (deg[i]) {
			bad = true;
			g[i][i >> 6] ^= (ull)1 << (i & 63);
			g[i][m] ^= 1;
		}
	}
	if (!bad) {
		printf("1\n");
		for (int i = 0; i < n; i++)
			printf("1 ");
		printf("\n");
		return;
	}
	k = 0;
	for (int i = 0; i < n; i++) {
		b[i] = -1;
		int v = -1;
		for (int j = k; j < n; j++) {
			if ((g[j][i >> 6] >> (i & 63)) & 1) {
				v = j;
				break;
			}
		}
		if (v == -1) continue;
		swap(g[v], g[k]);
		b[i] = k;
		for (int j = k + 1; j < n; j++) {
			if (((g[j][i >> 6] >> (i & 63)) & 1) == 0) continue;
			for (int z = 0; z <= m; z++)
				g[j][z] ^= g[k][z];
		}
		k++;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] == -1) {
			ans[i] = 0;
			continue;
		}
		ans[i] = g[b[i]][m];
		for (int j = i + 1; j < n; j++)
			if ((g[b[i]][j >> 6] >> (j & 63)) & 1)
				ans[i] ^= ans[j];
	}
	printf("2\n");
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
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