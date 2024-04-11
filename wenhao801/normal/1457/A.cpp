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

int main () {
	int t = read();
	while (t--) {
		int n= read(), m = read(), r = read(), c = read();
		printf("%d\n", max(max(r - 1 + c - 1, r - 1 + m - c), max(n - r + c - 1, n - r + m - c)));
	}
	return 0;
}