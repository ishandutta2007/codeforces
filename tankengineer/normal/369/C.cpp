#include<vector>
#include<cstdio>

using namespace std;

const int N = 100005;

int n, m;

vector<pair<int, int> > edge[N];

vector<int> ans;

int dfs(int u, int fa, bool hasproblem) {
	int ret = 0;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i].first, c = edge[u][i].second;
		if (v == fa) {
			continue;
		} else {
			ret += dfs(v, u, c == 2);
		}
	}
	if (hasproblem && ret == 0) {
		ret = 1;
		ans.push_back(u);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		--u, --v;
		edge[u].push_back(make_pair(v, c));
		edge[v].push_back(make_pair(u, c));
	}
	int anscnt =dfs(0, -1, false);
	printf("%d\n", anscnt);
	for (int i = 0; i < (int)anscnt; ++i) {
		printf("%d%c", ans[i] + 1, i == anscnt - 1 ? '\n' : ' ');
	}
	return 0;
}