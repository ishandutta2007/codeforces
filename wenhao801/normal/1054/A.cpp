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

int main () {
	int x = read(), y =read(), z = read(), t1 = read(), t2 = read(), t3 = read();
	int c1 = abs(x - y) *t1;
	int c2 = 3 * t3 + t2 * (abs(x - z) + abs(x - y));
	// printf("%d %d\n", c1, c2);
	if (c2 <= c1) puts("YES"); else puts("NO");
	return 0;
}