#include <bits/stdc++.h>

int b[105][105], ans[105][105], n, m;

int l[105], r[105];
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		l[i] = 1, r[i] = m;
		for (int j = 1; j <= m; j++) scanf("%d", &b[i][j]);
		std::sort(b[i] + 1, b[i] + m + 1);
	}
	for (int j = 1; j <= m; j++) {
		int mn = 1;
		for (int i = 1; i <= n; i++) if (b[i][l[i]] < b[mn][l[mn]]) mn = i;
		for (int i = 1; i <= n; i++) ans[i][j] = b[i][i == mn ? (l[i]++) : (r[i]--)];
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}