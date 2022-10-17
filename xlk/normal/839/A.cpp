#include <bits/stdc++.h>
using namespace std;
int a[120];
int main() {
	int n, k, s = 0, x;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		s += x;
		int u = min(s, 8);
		k -= u;
		s -= u;
		if (k <= 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", -1);
	return 0;
}