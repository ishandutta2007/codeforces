#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 2000000001, N = 20;
int n, m, a[N], b[N], g[N + 1][N + 1], f[N + 1][N + 1], tmp[N + 1][N + 1];

void mul(int f[N + 1][N + 1], int g[N + 1][N + 1]) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			tmp[i][j] = INF;
			for (int k = 0; k <= n; ++k) {
				if (f[i][k] < INF && g[k][j] < INF) {
					tmp[i][j] = min(tmp[i][j], f[i][k] + g[k][j]);
				}
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			f[i][j] = tmp[i][j];
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			g[i][j] = INF;
			f[i][j] = INF;
		}
		f[i][i] = 0;
	}
	for (int i = 0; i < (1 << n); ++i) {
		int bar = 0, dep = 0, sum = 0;
		for (int j = 0; j < n; ++j) {
			int t = i >> j & 1;
			if (t) {
				++dep;
				sum += a[j];
			} else {
				--dep;
				sum += b[j];
			}
			bar = min(bar, dep);
		}
		for (int j = -bar; j <= n; ++j) {
			if (j + dep <= n && j + dep >= 0) {
				int u, v;
				u = j, v = j + dep;
				g[u][v] = min(g[u][v], sum);
			}
		}
	}
	for (int i = 30; i >= 0; --i) {
		mul(f, f);
		if (m >> i & 1) {
			mul(f, g);
		}
	}
	printf("%d\n", f[0][0]);
	return 0;
}