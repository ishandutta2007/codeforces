#include <bits/stdc++.h>
using namespace std;
vector<int>a[1000020][2];
int n, c, x, y, r[1000020], t, l;
char s[10];
int dfs(int x) {
	int p = ++l;
	if (a[p][0].size()) {
		sort(a[p][0].begin(), a[p][0].end());
		if (a[p][0].front() <= l || !dfs(a[p][0].back())) {
			return 0;
		}
	}
	r[++t] = p;
	if (a[p][1].size()) {
		sort(a[p][1].begin(), a[p][1].end());
		if (a[p][1].front() <= l || !dfs(max(x, a[p][1].back()))) {
			return 0;
		}
	} else if (l < x && !dfs(x)) {
		return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < c; i++) {
		scanf("%d%d%s", &x, &y, s);
		a[x][*s == 'R'].push_back(y);
	}
	if (dfs(n)) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", r[i]);
		}
	} else {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}