#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int n, m, EC, ans, dep[maxn], a[maxn];
vector<int> son[maxn];
void dfs(int x, int fa) {
	for (int& v : son[x])
		if (v != fa) {
			dep[v] = dep[x] + 1;
			dfs(v, x);
		}
	if (son[x].size() == 1) a[m++] = dep[x];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v); 
		son[u].push_back(v);
		son[v].push_back(u);
	}
	for (auto &r : son[1]) {
		m = 0;
		dfs(r, 1);
		sort(a, a + m);
		int now = a[0];
		for (int i = 1; i < m; ++i) now = max(now + 1, a[i]);
		ans = max(ans, now + 1);
	}
	printf("%d\n", ans);
}