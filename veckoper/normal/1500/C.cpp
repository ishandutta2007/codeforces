#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
int n, m, a[N][N], b[N][N], id[N], cnt[N];
bool clr[N];
inline bool Check(const vector<int> &ans) {
	for (int i = 1; i <= n; ++i) id[i] = i;
	for (auto u: ans) stable_sort(id + 1, id + n + 1, [&](int x, int y) { return a[x][u] < a[y][u]; });
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[id[i]][j] != b[i][j]) return 0;
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &b[i][j]);
		}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i < n; ++i) cnt[j] += (b[i][j] > b[i + 1][j]);
	}
	vector<int> ans;
	while (1) {
		int sp = -1;
		for (int i = 1; i <= m; ++i) if (!cnt[i]) {
			sp = i;
			break;
		}
		if (sp == -1) break;
		cnt[sp] = -1;
		for (int i = 1; i < n; ++i) if (!clr[i] && b[i][sp] < b[i + 1][sp]) {
			clr[i] = 1;
			for (int j = 1; j <= m; ++j) cnt[j] -= (b[i][j] > b[i + 1][j]);
		}
		ans.push_back(sp);
	}
	reverse(ans.begin(), ans.end());
	if (!Check(ans)) {
		puts("-1");
	} else {
		cout << ans.size() << endl;
		for (auto x: ans) printf("%d ", x);
		puts("");
	}
	return 0;
}