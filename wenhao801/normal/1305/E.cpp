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

int a[5050];

int main () {
	int n = read(), m = read();
	int i, j = 2; a[1] = 1, a[2] = 2;
	for (i = 3; i <= n; i++) {
		if ((i - 1) / 2 <= m) a[i] = j = i, m -= (i - 1) >> 1;
		else if (m) {
			for (j = i + 1; (2 * i - j - 1) / 2 > m; j++);
			a[i] = j, m = 0;
		}
		else a[i] = a[i - 1] + j + 1;
	}
	if (m) puts("-1");
	else for (i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}