#include <cstdio>
#include <vector>

const int N = 200000;
int n, a[N], sub[N];
long long ans = 0;
std::vector<int> g[N];

void dfs(int v, int pr) {
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr) {
		dfs(g[v][i], v);
		sub[v] = std::max(sub[v], sub[g[v][i]]);
	}
	ans += std::max(0, a[v] - sub[v]);
	sub[v] = std::max(sub[v], a[v]);
}

int main() {
	scanf("%d", &n);
	std::pair<int, int> mx;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		mx = std::max(mx, std::make_pair(a[i], i));
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	int o1 = 0, o2 = 0;
	for (int i = 0; i < (int)g[mx.second].size(); ++i) {
		dfs(g[mx.second][i], mx.second);
		int x = sub[g[mx.second][i]];
		if (x > o1) {
			o2 = o1;
			o1 = x;
		} else if (x > o2) o2 = x;
	}
	printf("%lld\n", ans + 2 * mx.first - o1 - o2);
	return 0;
}