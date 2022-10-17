#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int r, c, n, k;
int a[100], b[100];
int main() {
	scanf("%d%d%d%d", &r, &c, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
	}
	int ans = 0;
	for (int i1 = 0; i1 < r; i1++) {
		for (int j1 = 0; j1 < c; j1++) {
			for (int i2 = i1; i2 < r; i2++) {
				for (int j2 = j1; j2 < c; j2++) {
					int c = 0;
					for (int t = 0; t < n; t++) {
						if (i1 <= a[t] && a[t] <= i2 && j1 <= b[t] && b[t] <= j2) {
							c++;
						}
					}
					if (c >= k) {
						ans += 1;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}