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

int a[1 << 18];
int main () {
	int n = read(), r = read(), i; double qwq = 1.0 / (1 << n); long long s = 0;
	for (i = 0; i < (1 << n); i++) a[i] = read(), s += a[i];
	printf("%.7lf\n", qwq * s);
	while (r--) { int x = read(), y = read(); s += -a[x] + y; a[x] = y; printf("%.7lf\n", qwq * s); }
	return 0;
}