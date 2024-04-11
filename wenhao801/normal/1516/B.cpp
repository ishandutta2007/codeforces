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

int a[2020];

int main () {
	int T = read();
	while (T--) {
		int n = read(), i, j, all = 0, fin = 0;
		for (i = 1; i <= n; i++) a[i] = read() ^ a[i - 1];
		if (!a[n]) { puts("YES"); continue; }
		for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++)
			if ((a[i] == (a[j] ^ a[i])) && (a[i] == (a[n] ^ a[j]))) fin = 1;
		puts(fin ? "YES" : "NO");
	}
	return 0;
}