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
		int a = read(), b = read();
		if (a == 0 && b == 0) puts("0");
		else if ((a & 1) != (b & 1)) puts("-1");
		else if (a == b) puts("1"); else puts("2");
	}
	return 0;
}