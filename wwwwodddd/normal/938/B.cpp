#include <bits/stdc++.h>
using namespace std;
int n, a[1000020];
int main() {
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	n += 2;
	a[n - 1] = 1000000;
	int z = 1000000;
	for (int i = 1; i < n; i++) {
		z = min(z, max(a[i - 1] - 1, 1000000 - a[i]));
	}
	printf("%d\n", z);
	return 0;
}