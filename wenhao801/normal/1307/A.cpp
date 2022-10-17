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

int T;
int n, d;
int a[101] = {};

int main () {
	T = read();
	while (T--) {
		n = read(), d = read();
		for (int i =1; i <= n; i++) a[i] = read();
		for (int i = 2; i <= n; i++) {
			if ((i - 1) * a[i] <= d) {
				d -= a[i] * (i - 1);
				a[1] += a[i];
			}
			else {
				a[1] += d / (i - 1);
				break;
			}
		}
		printf("%d\n", a[1]);
	}
	return 0;
}