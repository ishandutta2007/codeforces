#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005, LOG = 21;
int n, fa[N][LOG], col[N], dep[N], best[3], node[3][2], len[3];

int size, ans;

int lca(int u, int v) {
	if (dep[v] > dep[u]) {
		swap(u, v);
	}
	int len = dep[u] - dep[v];
	for (int i = LOG - 1; i >= 0; --i) {
		if (len >> i & 1) {
			u = fa[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; --i) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

void newnode(int f) {
	int u = size++;
	col[u] = col[f];
	dep[u] = dep[f] + 1;
	best[col[u]] = max(best[col[u]], dep[u]);
	fa[u][0] = f;
	for (int i = 1; fa[u][i - 1] != -1 && i < LOG; ++i) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	int c = col[u];
	int w = lca(u, node[c][0]), l1 = dep[u] + dep[node[c][0]] - 2 * dep[w];
	int w2 = lca(u, node[c][1]), l2 = dep[u] + dep[node[c][1]] - 2 * dep[w2];
	int t = l1 > l2;
	if (max(l1, l2) > len[c]) {
		len[c] = max(l1, l2);
		node[c][t] = u;
	}
}

void cal() {
	ans = max(ans, max(best[0] + best[1], max(best[1] + best[2], best[2] + best[0])));
	ans = max(ans, max(len[0], max(len[1], len[2])));
}

int main() {
	scanf("%d", &n);
	memset(fa, -1, sizeof(fa));
	col[1] = 0, col[2] = 1, col[3] = 2;
	dep[1] = dep[2] = dep[3] = 1;
	best[0] = best[1] = best[2] = 1;
	node[0][0] = node[0][1] = 1;
	node[1][0] = node[1][1] = 2;
	node[2][0] = node[2][1] = 3;
	len[0] = len[1] = len[2] = 0;
	size = 4, ans = 3;
	while (n--) {
		int u;
		scanf("%d", &u);
		--u;
		newnode(u);
		newnode(u);
		cal();
		printf("%d\n", ans);
	}
	return 0;
}