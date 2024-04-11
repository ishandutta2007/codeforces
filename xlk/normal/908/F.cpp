#include <bits/stdc++.h>
using namespace std;
int n, x, z, lr, lg, lb, mr, mb;
char c;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &x, &c);
		if (c == 'R' || c == 'G') {
			if (lr > 0) {
				z += x - lr;
				mr = max(mr, x - lr);
			}
			lr = x;
		}
		if (c == 'B' || c == 'G') {
			if (lb > 0) {
				z += x - lb;
				mb = max(mb, x - lb);
			}
			lb = x;
		}
		if (c == 'G') {
			if (lg > 0 && mr + mb > x - lg) {
				z += x - lg - mr - mb;
			}
			lg = x;
			mr = mb = 0;
		}
	}
	printf("%d\n", z);
	return 0;
}