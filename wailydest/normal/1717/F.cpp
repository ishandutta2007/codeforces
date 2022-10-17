#include <cstdio>
#include <cstring>
#include <vector>

struct edge {
	int to, cap, flow;
};

const int N = 10005;
int n, m, s[N], a[N], x[N], y[N];
std::vector<int> g[N];
std::vector<edge> e;
bool u[N];

void add_edge(int a, int b, int c) {
	g[a].push_back(e.size());
	e.push_back({b, c, 0});
	g[b].push_back(e.size());
	e.push_back({a, 0, 0});
}

bool dfs(int v) {
	if (v == n + 1) return 1;
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) if (!u[e[g[v][i]].to] && e[g[v][i]].flow < e[g[v][i]].cap && dfs(e[g[v][i]].to)) {
		++e[g[v][i]].flow;
		--e[g[v][i] ^ 1].flow;
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", s + i);
		if (!s[i]) pos = i;
	}
	int val = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		val += a[i];
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		x[i] = u;
		y[i] = v;
		--u;
		--v;
		if (!s[u]) u = pos;
		if (!s[v]) v = pos;
		++a[u];
		--a[v];
		add_edge(u, v, 1);
	}
	bool ok = 1;
	if (pos != -1) a[pos] -= val;
	else if (val) ok = 0;
	val = 0;
	for (int i = 0; i < n; ++i) if (a[i] || i == pos) {
		if (a[i] & 1) ok = 0;
		if (a[i] > 0) {
			add_edge(n, i, a[i] / 2);
			val += a[i] / 2;
		} else add_edge(i, n + 1, -a[i] / 2);
	}
	while (memset(u, 0, sizeof u), dfs(n)) --val;
	if (val) ok = 0;
	if (ok) {
		printf("YES\n");
		for (int i = 0; i < m; ++i) {
			if (e[i << 1].flow) std::swap(x[i], y[i]);
			printf("%d %d\n", x[i], y[i]);
		}
	} else printf("NO\n");
	return 0;
}