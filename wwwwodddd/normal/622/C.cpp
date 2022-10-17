#include <iostream>
#include <cstdio>
using namespace std;
int n, m, l, r, x;
int a[1000020];
int b[1000020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}	
	for (int i = n; i >= 1; i--) {
		if (i == n) {
			b[i] = n + 1;
		} else if (a[i] == a[i + 1]) {
			b[i] = b[i + 1];
		} else {
			b[i] = i + 1;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &l, &r, &x);
		if (a[l] != x) {
			printf("%d\n", l);
		} else {
			if (b[l] <= r) {
				printf("%d\n", b[l]);
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}