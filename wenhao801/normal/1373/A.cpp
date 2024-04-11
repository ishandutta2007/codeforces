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
	int T = read();
	while (T--) {
		long long a = read(), b = read(), c = read();
		if (a * b <= c) { puts("1 -1"); }
		else {
			if (a < c) { printf("1 %lld\n", b); }
			else if (a == c) printf("-1 %lld\n", b);
			else printf("-1 1\n");
		}
	}
	return 0;
}