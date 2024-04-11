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

const int MAXN = 2097152, LIM = 20;
int n, a[MAXN], mx1[MAXN], mx2[MAXN];
void SOS () {
	for (int i = 0; i <= LIM; i++) for (int j = 0; j < (1 << (LIM + 1)); j++) if (!((j >> i) & 1)) {
		int k = j ^ (1 << i);
		if (mx1[k] > mx1[j]) mx2[j] = mx1[j], mx1[j] = mx1[k]; else if (mx1[j] > mx1[k] && mx1[k] > mx2[j]) mx2[j] = mx1[k];
		if (mx2[k] > mx1[j]) mx2[j] = mx1[j], mx1[j] = mx2[k]; else if (mx1[j] > mx2[k] && mx2[k] > mx2[j]) mx2[j] = mx2[k];
	}
}

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n; i++) mx2[a[i]] = mx1[a[i]], mx1[a[i]] = i;
	SOS(); int ans = 0;
	for (i = 1; i <= n - 2; i++) {
		int now = 0;
		for (j = LIM; j >= 0; j--) {
			if ((a[i] >> j) & 1) continue;
			if (mx2[now | (1 << j)] > i) now |= 1 << j;
		}
		ans = max(ans, now | a[i]);
	}
	printf("%d\n", ans);
	return 0;
}