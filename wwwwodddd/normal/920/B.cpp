#include <bits/stdc++.h>
using namespace std;
int z[1020];
int t, n;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		int c = 0;
		for (int i = 0; i < n; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			c = max(c, l);
			if (c > r) {
				printf("0");
			} else {
				printf("%d", c);
				c++;
			}
			printf("%c", i == n - 1 ? '\n' : ' ');
		}
	}
}