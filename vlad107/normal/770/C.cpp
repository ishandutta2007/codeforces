#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
 	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> t(k);
	for (int &x: t) scanf("%d", &x);
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; i++) {
		int sz;
		scanf("%d", &sz);
		g[i].resize(sz);
		for (int &x: g[i]) scanf("%d", &x);
	}
	vector<int> used(n + 1); 
	vector<int> ans;
	function<void(int)> dfs = [&](int x) {
		if (used[x] == 2) return;
		if (used[x] == 1) {
			puts("-1");
			exit(0);
		}
		used[x] = 1;
		for (int y : g[x]) {
			dfs(y);
		}
		ans.push_back(x);
		used[x] = 2;
	};
	for (int x: t) dfs(x);
	printf("%d\n", (int)ans.size());
	for (int x: ans) printf("%d ", x);
	puts("");
}