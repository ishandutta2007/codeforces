#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n;
int a[100100] = {};

signed main () {
	int T = read();
	while (T--) {
		n = read();
		int i, j, s = 0;
		for (i = 1; i <= n; i++) a[i] = read(), s += a[i];
		bool f = false;
		for (i = 1; i <= n; i++) a[i] += a[i - 1]; a[n + 1] = 1e9 + 7;
		int Min = 0, secMin = n + 1;
		for (i = 1; i <= n; i++) {
			if (!(i == n && Min == 0) && a[i] - a[Min] >= s) { f = true; break; }
			if (i == n && Min == 0 && a[i] - a[secMin] >= s) { f = true; break; }
			if (a[i] < a[Min]) secMin = Min, Min = i;
			else if (a[i] < a[secMin]) secMin = i;
		}
		if (f) puts("NO"); else puts("YES");
	}
	return 0;
}