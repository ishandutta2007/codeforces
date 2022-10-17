#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 400000;
const int V = N * 4;
int n, q, pr[N], in[N], out[N], ord[V], cmp[V], r[N][2];
std::vector<int> g[N], g0[V], g1[V];
char s[N + 1];
bool ch[N], u[V];

void dfs(int v) {
	static int dt = 0;
	in[v] = dt++;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr[v]) {
		pr[g[v][i]] = v;
		dfs(g[v][i]);
	}
	out[v] = dt;
}

bool par(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

std::vector<int> path(int u, int v) {
	std::vector<int> res;
	while (true) {
		res.push_back(u);
		if (par(u, v)) break;
		u = pr[u];
	}
	return res;
}

void add_edge(int u, int v) {
	g0[u].push_back(v);
	g1[v].push_back(u);
}

void add(int u, int v) {
	add_edge(u, v);
	add_edge(v ^ 1, u ^ 1);
}

void dfs0(int v) {
	static int dt = 0;
	if (u[v]) return;
	u[v] = 1;
	for (int i = 0; i < (int)g0[v].size(); ++i) dfs0(g0[v][i]);
	ord[dt++] = v;
}

int cur;
void dfs1(int v) {
	if (cmp[v]) return;
	cmp[v] = cur;
	for (int i = 0; i < (int)g1[v].size(); ++i) dfs1(g1[v][i]);
}

void upd(int ind, int v, int r1, int r2) {
	if (!ch[v]) {
		ch[v] = 1;
		r[v][0] = r1;
		r[v][1] = r2;
	}
	int rcur[2] = {r1, r2};
	for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) if (rcur[i] != r[v][j]) add(ind * 2 + i, (q + v) * 2 + (j ^ 1));
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	bool ok = 1;
	for (int qi = 0; qi < q; ++qi) {
		int x, y;
		scanf("%d%d%s", &x, &y, s);
		--x;
		--y;
		std::vector<int> vec = path(x, y), vec1 = path(y, x);
		vec.pop_back();
		std::reverse(vec1.begin(), vec1.end());
		vec.insert(vec.end(), vec1.begin(), vec1.end());
		for (int i = 0; i < (int)vec.size(); ++i) upd(qi, vec[i], s[i] - 'a', s[(int)vec.size() - i - 1] - 'a');
	}
	for (int i = 0; i < V; ++i) dfs0(i);
	for (int i = V - 1; i >= 0; --i) if (!cmp[ord[i]]) {
		++cur;
		dfs1(ord[i]);
	}
	for (int i = 0; i < V; ++i) if (cmp[i] == cmp[i ^ 1]) ok = 0;
	if (ok) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) printf("%c", ch[i] ? 'a' + r[i][cmp[(q + i) * 2] < cmp[(q + i) * 2 + 1]] : 'a');
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}