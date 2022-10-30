#include<vector>
#include<cstdio>

using namespace std;

const int N = 200005;

int n, x;

vector<int> edge[N];

int dis[2][N];

void dfs(int u, int fa, int col) {
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i];
		if (v == fa) {
			continue;
		}
		dis[col][v] = dis[col][u] + 1;
		dfs(v, u, col);
	}
}

int main() {
	scanf("%d%d", &n, &x);
	--x;
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dis[0][0] = 0;
	dfs(0, -1, 0);
	dis[1][x] = 0;
	dfs(x, -1, 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (dis[1][i] < dis[0][i]) {
			ans = max(ans, dis[0][i]);
		}
	}
	printf("%d\n", ans * 2);
	return 0;
}