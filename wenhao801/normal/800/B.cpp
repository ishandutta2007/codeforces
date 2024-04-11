#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 1010;
int n; int a[MAXN], b[MAXN];

int main () {
	n = read(); int i, j;
	for (i = 0; i < n; i++) a[i] = read(), b[i] = read();
	a[n] = a[0], b[n] = b[0]; a[n + 1] = a[1], b[n + 1] = b[1];
	double ans = 1e18;
	for (i = 0; i < n; i++) {
		if (a[i] == a[i + 2]) ans = min(ans, 1.0 * abs(a[i] - a[i + 1]));
		else {
			double k = ((double)(b[i] - b[i + 2])) / ((double)(a[i] - a[i + 2]));
			double B = b[i] - k * a[i];
			// y = kx + b, kx - y + b = 0
			ans = min(ans, fabs(1.0 * (k * a[i + 1] - b[i + 1] + B) / sqrt(k * k + 1)));
		}
	}
	printf("%.8lf\n", ans / 2);
	return 0;
}