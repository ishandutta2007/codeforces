#include <bits/stdc++.h>

using namespace std;

int DFS(int u, int p, vector<vector<int>>& E) {
	int cnt = 0, ans = 1e9;
	for (int v : E[u]) {
		if (v != p) {
			ans = min(ans, DFS(v, u, E));
			++cnt;
		}
	}
	ans += 2;
	if (cnt == 0)
		ans = 1;
	else if (cnt == 1)
		ans = 2;
	return ans;
}

int main() {
	int tc;
	scanf("%i",&tc);
	while (tc--) {
		int n;
		scanf("%i", &n);
		vector<vector<int>> E(n + 1);
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%i %i", &u, &v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		int ans = DFS(1, 0, E);
		printf("%i\n", n - ans);
	}
    return 0;
}