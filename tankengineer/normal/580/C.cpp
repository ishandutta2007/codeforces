#include<vector>
#include<cstdio>

using namespace std;

const int N = 100005;

int n, m;

int hascat[N];

vector<int> edge[N];

int dfs(int u, int cntcat, int fa) {
	if (hascat[u]) {
		cntcat++;
		if (cntcat > m) {
			return 0;
		}
	} else {
		cntcat = 0;
	}
	int ret = 0;
	bool isleaf = true;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i];
		if (v == fa) {
			continue;
		} else {
			isleaf = false;
			ret += dfs(v, cntcat, u);
		}
	}
	if (isleaf) {
		ret = 1;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &hascat[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int ans = dfs(0, 0, -1);
	printf("%d\n", ans);
	return 0;
}