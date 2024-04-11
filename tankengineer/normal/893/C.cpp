#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100005;

int n, m;

bool vis[N];

int c[N];

vector<int> edge[N];

int dfs(int u) {
	vis[u] = true;
	int ret = c[u];
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i];
		if (!vis[v]) {
			ret = min(ret, dfs(v));
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", c + i);
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			ans += dfs(i);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}