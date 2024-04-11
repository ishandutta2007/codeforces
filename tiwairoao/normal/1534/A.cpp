#include <bits/stdc++.h>

int n, m; char s[55][55];

bool check0() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i + j) & 1) {
				if (s[i][j] == 'W') return false;
			} else {
				if (s[i][j] == 'R') return false;
			}
		}
	}
	return true;
}
bool check1() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i + j) & 1) {
				if (s[i][j] == 'R') return false;
			} else {
				if (s[i][j] == 'W') return false;
			}
		}
	}
	return true;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);

	if (check0()) {
		puts("Yes");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				putchar((i + j) & 1 ? 'R' : 'W');
			puts("");
		}
	} else if (check1()) {
		puts("Yes");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				putchar((i + j) & 1 ? 'W' : 'R');
			puts("");
		}
	} else {
		puts("No");
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}