#include <bits/stdc++.h>

const int N = 300;

char s[N + 5][N + 5];
int a[3][2], n, k;
void print(int o, int p) {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (s[i][j] != '.' && (i + j) % 3 == o) {
			if (p && s[i][j] == 'O') s[i][j] = 'X';
			else if (!p && s[i][j] == 'X') s[i][j] = 'O';
		}
	}
	o = (o == 2 ? 0 : o + 1), p = (!p);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (s[i][j] != '.' && (i + j) % 3 == o) {
			if (p && s[i][j] == 'O') s[i][j] = 'X';
			else if (!p && s[i][j] == 'X') s[i][j] = 'O';
		}
	}
	for (int i = 1; i <= n; i++) puts(s[i] + 1);
}
void solve() {
	scanf("%d", &n), k = 0;
	for (int o = 0; o < 3; o++) a[o][0] = a[o][1] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; j++) if (s[i][j] != '.') {
			k++;
			if (s[i][j] == 'X') a[(i + j) % 3][0]++;
			else a[(i + j) % 3][1]++;
		}
	}
	for (int o = 0; o < 3; o++) for (int p = 0; p < 2; p++) {
		if (a[o][p] + a[o == 2 ? 0 : o + 1][!p] <= k / 3 ) {
			print(o, p); return;
		}
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}