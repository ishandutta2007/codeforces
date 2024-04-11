#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 300300;
int n, m; vector <int> a[MAXN], ans[MAXN];

char s[MAXN];

string _ = "AGCT";
int __[555];

int row[MAXN][4][2], col[MAXN][4][2];
int calc_r (int r, int p, int q) {
	return m - row[r][p][1] - row[r][q][0];
}
int calc_c (int c, int p, int q) {
	return n - col[c][p][1] - col[c][q][0];
}
void fill_r (int r, int p, int q) {
	for (int i = 1; i <= m; i++) ans[r][i] = (i & 1) ? p : q;
}
void fill_c (int c, int p, int q) {
	for (int i = 1; i <= n; i++) ans[i][c] = (i & 1) ? p : q;
}

int main () {
	n = read(), m = read(); int i, j;
	for (i = 0; i < 4; i++) __[_[i]] = i;
	for (i = 0; i <= n + 1; i++) a[i].resize(m + 2), ans[i].resize(m + 2);
	for (i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (j = 1; j <= m; j++) a[i][j] = __[s[j]], ++row[i][a[i][j]][j & 1], ++col[j][a[i][j]][i & 1];
	}
	// for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) printf("%d%c", a[i][j], " \n"[j == m]);
	int tmp[4] = {0, 1, 2, 3}, ans = 1e9, ctmp[4], pos, isc = -2;
	do {
		int now = 0;
		for (i = 1; i <= n; i++) {
			if (i & 1) now += calc_r(i, tmp[0], tmp[1]);
			else now += calc_r(i, tmp[2], tmp[3]);
		}

		if (now < ans) ans = now, isc = -1, memcpy(ctmp, tmp, sizeof tmp);

		now = calc_c(1, tmp[0], tmp[2]) + calc_c(2, tmp[1], tmp[3]);
		for (i = m; i >= 3; i--) {
			if (i & 1) now += min(calc_c(i, tmp[0], tmp[2]), calc_c(i, tmp[2], tmp[0]));
			else now += min(calc_c(i, tmp[1], tmp[3]), calc_c(i, tmp[3], tmp[1]));
		}
		for (i = 3; i <= m; i++) {
			if (i & 1) {
				now -= min(calc_c(i, tmp[0], tmp[2]), calc_c(i, tmp[2], tmp[0]));
				if (now + calc_c(i, tmp[2], tmp[0]) < ans) ans = now + calc_c(i, tmp[2], tmp[0]), memcpy(ctmp, tmp, sizeof tmp), pos = i, isc = 1;
				now += calc_c(i, tmp[0], tmp[2]);
			}
			else {
				now -= min(calc_c(i, tmp[1], tmp[3]), calc_c(i, tmp[3], tmp[1]));
				if (now + calc_c(i, tmp[3], tmp[1]) < ans) ans = now + calc_c(i, tmp[3], tmp[1]), memcpy(ctmp, tmp, sizeof tmp), pos = i, isc = 1;
				now += calc_c(i, tmp[1], tmp[3]);
			}
		}
		
		now = calc_r(1, tmp[0], tmp[1]) + calc_r(2, tmp[2], tmp[3]);
		for (i = n; i >= 3; i--) {
			if (i & 1) now += min(calc_r(i, tmp[0], tmp[1]), calc_r(i, tmp[1], tmp[0]));
			else now += min(calc_r(i, tmp[2], tmp[3]), calc_r(i, tmp[3], tmp[2]));
		}
		for (i = 3; i <= n; i++) {
			if (i & 1) {
				now -= min(calc_r(i, tmp[0], tmp[1]), calc_r(i, tmp[1], tmp[0]));
				if (now + calc_r(i, tmp[1], tmp[0]) < ans) ans = now + calc_r(i, tmp[1], tmp[0]), memcpy(ctmp, tmp, sizeof tmp), pos = i, isc = 0;
				now += calc_r(i, tmp[0], tmp[1]);
			}
			else {
				now -= min(calc_r(i, tmp[2], tmp[3]), calc_r(i, tmp[3], tmp[2]));
				if (now + calc_r(i, tmp[3], tmp[2]) < ans) ans = now + calc_r(i, tmp[3], tmp[2]), memcpy(ctmp, tmp, sizeof tmp), pos = i, isc = 0;
				now += calc_r(i, tmp[2], tmp[3]);
			}
		}
	} while (next_permutation(tmp, tmp + 4));
	// printf("%d\n", ans);
	memcpy(tmp, ctmp, sizeof tmp);
	// printf("%d (%d %d %d %d) %d\n", isc, tmp[0], tmp[1], tmp[2], tmp[3], pos);
	if (isc == -1) {
		for (i = 1; i <= n; i++) { if (i & 1) fill_r(i, tmp[0], tmp[1]); else fill_r(i, tmp[2], tmp[3]); }
	}
	else if (isc == 0) {
		for (i = 1; i < pos; i++) {
			if (i & 1) fill_r(i, tmp[0], tmp[1]); else fill_r(i, tmp[2], tmp[3]);
		}
		if (i & 1) fill_r(i, tmp[1], tmp[0]); else fill_r(i, tmp[3], tmp[2]);
		for (i = pos + 1; i <= n; i++) {
			if (i & 1) {
				if (calc_r(i, tmp[0], tmp[1]) < calc_r(i, tmp[1], tmp[0]))
					fill_r(i, tmp[0], tmp[1]);
				else fill_r(i, tmp[1], tmp[0]);
			}
			else {
				if (calc_r(i, tmp[2], tmp[3]) < calc_r(i, tmp[3], tmp[2]))
					fill_r(i, tmp[2], tmp[3]);
				else fill_r(i, tmp[3], tmp[2]);
			}
		}
	}
	else {
		for (i = 1; i < pos; i++) {
			if (i & 1) fill_c(i, tmp[0], tmp[2]); else fill_c(i, tmp[1], tmp[3]);
		}
		if (i & 1) fill_c(i, tmp[2], tmp[0]); else fill_c(i, tmp[3], tmp[1]);
		for (i = pos + 1; i <= m; i++) {
			if (i & 1) {
				if (calc_c(i, tmp[0], tmp[2]) < calc_c(i, tmp[2], tmp[0]))
					fill_c(i, tmp[0], tmp[2]);
				else fill_c(i, tmp[2], tmp[0]);
			}
			else {
				if (calc_c(i, tmp[1], tmp[3]) < calc_c(i, tmp[3], tmp[1]))
					fill_c(i, tmp[1], tmp[3]);
				else fill_c(i, tmp[3], tmp[1]);
			}
		}
	}
	for (i = 1; i <= n; i++, putchar('\n')) for (j = 1; j <= m; j++) putchar(_[::ans[i][j]]);
	return 0;
}