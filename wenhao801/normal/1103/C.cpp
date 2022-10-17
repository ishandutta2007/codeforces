#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 500500;
vector <int> E[MAXN];

int n, m, K, dep[MAXN], fa[MAXN];
bool leaf[MAXN];

void dfs (int x, int f) {
	dep[x] = dep[f] + 1, fa[x] = f, leaf[x] = 1;
	for (auto i: E[x]) if (!dep[i]) dfs(i, x), leaf[x] = 0;
}

int main () {
	n = read(), m = read(), K = read();
	int i, j;
	for (i = 1; i <= m; i++) { int u = read(), v = read(); E[u].push_back(v), E[v].push_back(u); }
	dfs(1, 0);
	for (i = 1; i <= n; i++) if (dep[i] >= n / K + (n % K != 0)) {
		puts("PATH"); printf("%d\n", dep[i]);
		while (i) { printf("%d ", i); i = fa[i]; }
		return 0;
	}
	puts("CYCLES");
	for (i = 1; i <= n; i++) if (K && leaf[i]) {
		int u = 0, v = 0;
		--K; for (auto j: E[i]) if (j != fa[i]) {
			if (!u) u = j;
			else if (!v) v = j;
		}
		if ((dep[i] - dep[u] + 1) % 3 != 0) {
			printf("%d\n", dep[i] - dep[u] + 1);
			for (j = i; dep[j] >= dep[u]; j = fa[j]) printf("%d ", j);
			putchar('\n');
		} else if ((dep[i] - dep[v] + 1) % 3 != 0) {
			printf("%d\n", dep[i] - dep[v] + 1);
			for (j = i; dep[j] >= dep[v]; j = fa[j]) printf("%d ", j);
			putchar('\n');
		}
		else {
			if (dep[u] < dep[v]) swap(u, v);
			printf("%d\n", dep[u] - dep[v] + 2);
			for (j = u; dep[j] >= dep[v]; j = fa[j]) printf("%d ", j);
			printf("%d\n", i);
		}
	}
	return 0;
}