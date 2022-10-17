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

int a[101] = {};

int main () {
	int T = read();
	while (T--) {
		int i, j;
		int n = read(), m = read(), k = read();
		for (i = 1; i <= n; i++)
			a[i] = read();
		bool f = true;
		for (i = 1; i < n; i++) {
			if (m < 0 || a[i] + k + m < a[i + 1]) {
				f = false;
				break;
			}
			if (a[i + 1] - a[i] > k) {
				m -= a[i + 1] - a[i] - k;
			}
			else {
				m += a[i] - a[i + 1];
				if (a[i + 1] >= k) m += k;
				else m += a[i + 1];
			}
		}
		if (!f) puts("NO"); else puts("YES");
	}
	return 0;
}