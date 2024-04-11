#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	long long x, y, m;
	scanf("%I64d %I64d %I64d", &x, &y, &m);
	if (x <= 0 && y <= 0) {
		if (x < m && y < m) {
			printf("-1");
		} else {
			printf("0");
		}
	} else {
		long long ans = 0;
		if (x < m && y < m && (x < 0 || y < 0)) {
			if (y <= 0) {
				swap(x, y);
			}
			long long k = -x / y + 1;
			ans += k;
			x = k * y + x;
		}
		while (x < m && y < m) {
			long long t = x + y;
			if (x < y) {
				x = t;
			} else {
				y = t;
			}
			ans++;
		}
		printf("%I64d", ans);
	}
	return 0;
}