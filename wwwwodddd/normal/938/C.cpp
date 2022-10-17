#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		long long x, n, m;
		scanf("%lld", &x);
		n = m = 1;
		while (true) {
			if (n * n - m * m > x) {
				m++;
			} else if (n * n - m * m < x) {
				n++;
			} else {
				if (m == n / (n / m)) {
					printf("%lld %lld\n", n, n / m);
					break;
				} else {
					n++;
					m++;
				}
			}
			if (n > 1000000) {
				printf("-1\n");
				break;
			}
		}
	}
}