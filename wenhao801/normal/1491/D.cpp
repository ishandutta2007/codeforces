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

int lowbit (int x) { return x & -x; }
int main () {
	int T = read();
	while (T--) {
		int x = read(), y = read();
		if (x > y) { puts("NO"); continue; }
		if (__builtin_popcount(y) > __builtin_popcount(x)) { puts("NO"); continue; }
		if ((y & -y) < (x & -x)) { puts("NO"); continue; }
		while (y) {
			if (lowbit(y) < lowbit(x)) break;
			x -= lowbit(x), y -= lowbit(y);
		}
		if (y) puts("NO"); else puts("YES");
	}
	return 0;
}