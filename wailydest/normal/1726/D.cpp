#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 200005;
int t, n, m, up[N], to[N * 2], dep[N];
bool col[N];
std::vector<int> g[N], edg;

void dfs(int v, int pr = -1) {
	if (!dep[v]) dep[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) {
		int s = to[g[v][i]];
		if (s != pr) {
			if (dep[s]) {
				if (dep[s] < dep[v]) edg.push_back(g[v][i] >> 1);
			} else {
				up[s] = g[v][i] ^ 1;
				dep[s] = dep[v] + 1;
				dfs(s, v);
			}
		}
	}
}

bool cmp(int a, int b) {
	return abs(dep[to[a << 1]] - dep[to[a << 1 | 1]]) < abs(dep[to[b << 1]] - dep[to[b << 1 | 1]]);
}

bool tri() {
	if (edg.size() != 3) return 0;
	std::vector<int> ve;
	for (int i = 0; i < edg.size(); ++i) {
		ve.push_back(to[edg[i] << 1]);
		ve.push_back(to[edg[i] << 1 | 1]);
	}
	std::sort(ve.begin(), ve.end());
	for (int i = 0; i < 6; i += 2) if (ve[i] != ve[i + 1]) return 0;
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			dep[i] = 0;
		}
		edg.clear();
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			to[i << 1] = b;
			to[i << 1 | 1] = a;
			g[a].push_back(i << 1);
			g[b].push_back(i << 1 | 1);
		}
		dfs(0);
		for (int i = 0; i < m; ++i) col[i] = 0;
		for (int i = 0; i < edg.size(); ++i) col[edg[i]] = 1;
		if (tri()) {
			std::sort(edg.begin(), edg.end(), cmp);
			int a = to[edg[0] << 1], b = to[edg[0] << 1 | 1];
			if (dep[a] < dep[b]) std::swap(a, b);
			col[up[a] >> 1] = 1;
			col[edg[0]] = 0;
		}
		for (int i = 0; i < m; ++i) printf("%d", (int)col[i]);
		printf("\n");
	}
	return 0;
}