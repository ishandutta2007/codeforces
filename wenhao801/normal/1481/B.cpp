#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 110;
int a[MAXN];

int main () {
	int T = read();
	while (T--) {
		int i, j, n = read(), k = read();
		for (i = 1; i <= n; i++) a[i] = read();
		while (k--) {
			for (i = 1; i < n; i++) {
				if (a[i] >= a[i + 1]);
				else { ++a[i]; break; }
			}
			if (i == n) break;
		}
		printf("%d\n", i == n ? -1 : i);
	}
	return 0;
}