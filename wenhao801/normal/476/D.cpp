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
	int n = read(), k = read();
	printf("%lld\n", (6ll * (n - 1) + 5) * k);
	for (int i = 0; i < n; i++) printf("%lld %lld %lld %lld\n", (6ll * i + 1) * k, (6ll * i + 2) * k, (6ll * i + 3) * k, (6ll * i + 5) * k);
	return 0;
}