#include <cstdio>
#include <vector>

const int N = 200000;
int t, n, ans;
bool c[N];
std::vector<int> g[N];

void dfs(int v, int pr = -1) 
{
	bool leaf = true;
	c[v] = 0;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr) {
		leaf = false;
		dfs(g[v][i], v);
		c[v] = c[v] || c[g[v][i]];
	}
	if (leaf) c[v] = 1;
	else c[v] = !c[v];
	if (v) {
		if (!c[v]) --ans;
		else ++ans;
	}
	else if (!c[v]) --ans;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}
		ans = 0;
		dfs(0);
		printf("%d\n", ans + 1);
		for (int i = 0; i < n; ++i) g[i].clear();
	}
	return 0;
}