#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &k);
		int l = 0, r;
		int z = 0;
		for (int i = 0; i < k; i++) {
			scanf("%d", &r);
			if (l == 0) {
				z = max(z, r);
			} else {
				z = max(z, (r - l) / 2 + 1);
			}
			l = r;
		}
		z = max(z, (n - l + 1));
		printf("%d\n", z);
	}
}