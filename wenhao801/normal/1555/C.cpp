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

int n, a[100100][2];

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		a[n + 1][0] = a[n + 1][1] = 0;
		for (i = 1; i <= n; i++) a[i][0] = read();
		for (i = 1; i <= n; i++) a[i][1] = read();
		for (i = 1; i <= n; i++) a[i][1] += a[i - 1][1];
		for (i = n - 1; i >= 1; i--) a[i][0] += a[i + 1][0];
		int ans = 2e9 + 7;
		for (i = 1; i <= n; i++) ans = min(ans, max(a[i + 1][0], a[i - 1][1]));
		cout << ans << endl;
	}
	return 0;
}