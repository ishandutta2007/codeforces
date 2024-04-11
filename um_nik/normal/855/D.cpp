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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
const int LOG = 18;
int n, q;
int a[N], b[N], c[N];
int h[N];
int par[N][LOG];

int up(int v, int dh) {
	if (dh < 0) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (dh < (1 << k)) continue;
		dh -= 1 << k;
		v = par[v][k];
	}
	return v;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < LOG; j++)
			par[i][j] = -1;
	for (int v = 0; v < n; v++) {
		int u, t;
		scanf("%d%d", &u, &t);
		if (u == -1) {
			a[v] = v;
			b[v] = 0;
			c[v] = v;
			continue;
		}
		u--;
		h[v] = h[u] + 1;
		b[v] = b[u];
		par[v][0] = u;
		for (int k = 0; k < LOG - 1; k++) {
			int w = par[v][k];
			if (w == -1) break;
			par[v][k + 1] = par[w][k];
		}
		if (t == 0) {
			a[v] = a[u];
			c[v] = v;
		} else {
			a[v] = v;
			c[v] = c[u];
			b[v]++;
		}
	}
	scanf("%d", &q);
	while(q--) {
		int t, v, u;
		scanf("%d%d%d", &t, &v, &u);
		v--;u--;
		if (v == u) {
			printf("NO\n");
			continue;
		}
		if (t == 1) {
			if (b[v] != b[u]) {
				printf("NO\n");
				continue;
			}
			if (v == up(u, h[u] - h[v]))
				printf("YES\n");
			else
				printf("NO\n");
		} else {
			if (b[v] >= b[u]) {
				printf("NO\n");
				continue;
			}
			int w = a[v];
			if (h[c[u]] <= h[w] && w == up(u, h[u] - h[w])) {
				printf("YES\n");
				continue;
			}
			u = c[u];
			if (b[v] != b[u]) {
				printf("NO\n");
				continue;
			}
			if (up(v, h[v] - h[u]) == u)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}