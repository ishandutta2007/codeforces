#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 200200;
int n, m; char s[MAXN];
int cnt[MAXN][3][3];

#define q(l,r,c,p) (cnt[r][p][c] - cnt[l - 1][p][c])

int main () {
	n = read(), m = read(); scanf("%s", s + 1);
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) cnt[i][j][k] = cnt[i - 1][j][k];
		}
		++cnt[i][i % 3][s[i] - 'a'];
	}
	while (m--) {
		int l = read(), r = read();
		int ans = r - l + 1;
		ans = min(ans, r - l + 1 - q(l, r, 0, 0) - q(l, r, 1, 1) - q(l, r, 2, 2));
		ans = min(ans, r - l + 1 - q(l, r, 0, 0) - q(l, r, 1, 2) - q(l, r, 2, 1));
		// printf("%d %d %d\n", q(l, r, 0, 0), q(l, r, 1, 2), q(l, r, 2, 1));
		ans = min(ans, r - l + 1 - q(l, r, 0, 1) - q(l, r, 1, 0) - q(l, r, 2, 2));
		ans = min(ans, r - l + 1 - q(l, r, 0, 1) - q(l, r, 1, 2) - q(l, r, 2, 0));
		ans = min(ans, r - l + 1 - q(l, r, 0, 2) - q(l, r, 1, 0) - q(l, r, 2, 1));
		ans = min(ans, r - l + 1 - q(l, r, 0, 2) - q(l, r, 1, 1) - q(l, r, 2, 0));
		cout << ans << endl;
		
	}
	return 0;
}