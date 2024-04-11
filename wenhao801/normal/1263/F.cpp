#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 4040;
int dp[MAXN][MAXN] = {};

struct Edge {
	int nex;
	int to;
} edge[MAXN << 3];
int head[MAXN << 2], cnt = 0;

void add (int u, int v) {
	edge[++cnt].to = v;
	edge[cnt].nex = head[u];
	head[u] = cnt;
}

int n, a, b;
int afa[MAXN << 1][22], bfa[MAXN << 1][22];
int depa[MAXN << 1], depb[MAXN << 1];

void dfsa (int x, int f) {
	afa[x][0] = f;
	depa[x] = depa[f] + 1;
    if (x <= n) return;
	int i, j;
	for (i = head[x]; i; i = edge[i].nex) {
		j = edge[i].to;
		if (j == f) continue;
		dfsa(j, x);
	}
}

void dfsb (int x, int f) {
	bfa[x][0] = f;
	depb[x] = depb[f] + 1;
    if (x <= n) return;
	int i, j;
	for (i = head[x]; i; i = edge[i].nex) {
		j = edge[i].to;
		if (j == f) continue;
		dfsb(j, x);
	}
}

int alca (int u, int v) {
	if (depa[u] < depa[v]) swap(u, v);
    if (v == 0) return n + 1;
	int i, j;
	for (i = 20; i >= 0; i--)
		if (depa[afa[u][i]] >= depa[v]) u = afa[u][i];
	if (u == v) return u;
	for (i = 20; i >= 0; i--)
		if (afa[u][i] != afa[v][i]) u = afa[u][i], v = afa[v][i];
	return afa[u][0];
}

int blca (int u, int v) {
	if (depb[u] < depb[v]) swap(u, v);
    if (v == 0) return n + a + 1;
	int i, j;
	for (i = 20; i >= 0; i--)
		if (depb[bfa[u][i]] >= depb[v]) u = bfa[u][i];
    if (u == v) return u;
	for (i = 20; i >= 0; i--)
		if (bfa[u][i] != bfa[v][i]) u = bfa[u][i], v = bfa[v][i];
	return bfa[u][0];
}

int A[MAXN], B[MAXN];

int main () {
	int i, j;
	n = read();
	a = read();
	for (i = 1; i < a; i++) {
		int x = read();
		add(n + x, n + i + 1), add(n + i + 1, n + x);
	}
	for (i = 1; i <= n; i++) {
		int x = read();
        A[i] = x + n;
		add(x + n, i), add(i, x + n);
	}
	b = read();
	for (i = 1; i < b; i++) {
		int x = read();
		add(n + a + x, n + a + i + 1), add(n + a + i + 1, n + a + x);
	}
	for (i = 1; i <= n; i++) {
		int x = read();
        B[i] = x + n + a;
		add(x + n + a, i), add(i, x + n + a);
	}
	dfsa(1 + n, 0);
	dfsb(1 + n + a, 0);
	for (i = 1; i <= 20; i++) {
		for (j = 1; j <= a; j++)
			afa[j + n][i] = afa[afa[j + n][i - 1]][i - 1];
		for (j = 1; j <= b; j++)
			bfa[j + a + n][i] = bfa[bfa[j + a + n][i - 1]][i - 1];
	}
    memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
            int t = max(i, j) + 1;
            dp[t][j] = min(dp[t][j], dp[i][j] + depa[A[t]] - depa[alca(A[t], A[i])]);
            dp[i][t] = min(dp[i][t], dp[i][j] + depb[B[t]] - depb[blca(B[t], B[j])]);
		}
    int ans = 0;
    for (i = 0; i < n; i++) { ans = max(ans, a + b - 2 - min(dp[i][n], dp[n][i])); }
    printf("%d\n", ans);
	return 0;
}