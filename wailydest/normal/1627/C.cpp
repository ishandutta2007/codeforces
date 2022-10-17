#include <cstdio>
#include <vector>
#include <utility>

const int N = 100000;
int t, n, ans[N];
std::vector<std::pair<int, int> > g[N];

void dfs(int v, int pr = -1, bool pa = 0) 
{
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i].first != pr) {
		ans[g[v][i].second] = pa ? 2 : 3;
		dfs(g[v][i].first, v, !pa);
	}
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool ok = 1;
		for (int i = 0; i < n; ++i) g[i].clear();
		for (int i = 1; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			g[a].push_back(std::make_pair(b, i));
			g[b].push_back(std::make_pair(a, i));
		}
		for (int i = 0; i < n; ++i) if (g[i].size() >= 3) ok = 0;
		if (ok) {
			int from;
			for (from = 0; g[from].size() > 1; ++from);
			dfs(from);
			for (int i = 1; i < n; ++i) printf("%d ", ans[i]);
			printf("\n");
		} else printf("-1\n");
	}
	return 0;
}