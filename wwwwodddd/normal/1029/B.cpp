#include <bits/stdc++.h>
using namespace std;
int n, x, c, z, p;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x > 2 * p) {
			c = 1;
		} else {
			c++;
		}
		z = max(z, c);
		p = x;
	}
	printf("%d\n", z);
	return 0;
}