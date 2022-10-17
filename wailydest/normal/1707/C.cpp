#include <cstdio>
#include <vector>

const int N = 100000;
const int LG = 18;
int n, m, top[N], up[LG][N], inc[N], in[N], out[N], ans[N];
std::vector<int> g[N];

int find(int v) {
	if (top[v] == -1) return v;
	return top[v] = find(top[v]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	top[b] = a;
	return 1;
}

bool par(int a, int b) {
	return in[a] <= in[b] && out[a] >= out[b];
}

void dfs(int v) {
	static int dt = 0;
	in[v] = dt++;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != up[0][v]) {
		up[0][g[v][i]] = v;
		dfs(g[v][i]);
	}
	out[v] = dt;
}

int low(int b, int a) {
	for (int i = LG - 1; i >= 0; --i) if (!par(up[i][b], a)) b = up[i][b];
	return b;
}

void dfs1(int v, int sum = 0) {
	sum += inc[v];
	if (!sum) ans[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != up[0][v]) dfs1(g[v][i], sum);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) top[i] = -1;
	std::vector<std::pair<int, int> > vec;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		if (merge(a, b)) {
			g[a].push_back(b);
			g[b].push_back(a);
		} else vec.push_back(std::make_pair(a, b));
	}
	dfs(0);
	for (int j = 1; j < LG; ++j) for (int i = 0; i < n; ++i) up[j][i] = up[j - 1][up[j - 1][i]];
	for (int i = 0; i < (int)vec.size(); ++i) {
		int a = vec[i].first, b = vec[i].second;
		if (par(b, a)) std::swap(a, b);
		if (par(a, b)) {
			++inc[low(b, a)];
			--inc[b];
		} else {
			++inc[0];
			--inc[a];
			--inc[b];
		}
	}
	dfs1(0);
	for (int i = 0; i < n; ++i) printf("%d", ans[i]);
	printf("\n");
	return 0;
}