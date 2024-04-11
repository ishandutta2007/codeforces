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

bool ispr (long long x) {
	long long i = 2;
	for (i = 2; i * i <= x; i++) if (x % i == 0) return 0;
	return 1;
}

int main () {
	int T = read(); while (T--) { long long a, b; cin >> a >> b; puts((a == b + 1 && ispr(a + b)) ? "YES" : "NO"); }
	return 0;
}