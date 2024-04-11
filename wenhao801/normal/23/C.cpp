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

struct dat { int u, v, id; bool operator < (const dat &tmp) const { return u < tmp.u; } } a[200200];

int main () {
	int T = read();
	while (T--) {
		int n = read(), i, j;
		for (i = 1; i <= 2 * n - 1; i++) {
			int u = read(), v = read();
			a[i].u = u, a[i].v = v, a[i].id = i;
		}
		sort(a + 1, a + 2 * n);
		puts("YES");
		for (i = 1; i < n; i++) printf("%d ", (a[2 * i - 1].v > a[2 * i].v ? a[2 * i - 1].id : a[2 * i].id));
		printf("%d\n", a[2 * n - 1].id);
	}
	return 0;
}