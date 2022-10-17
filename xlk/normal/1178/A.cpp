#include <bits/stdc++.h>
using namespace std;
int a[120];
int n, s, t, c;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	t = a[0];
	c = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] * 2 <= a[0]) {
			t += a[i];
			c++;
		}
	}
	if (2 * t > s) {
		printf("%d\n", c);
		printf("1");
		for (int i = 1; i < n; i++) {
			if (a[i] * 2 <= a[0]) {
				printf(" %d", i + 1);
			}
		}
		printf("\n");
	} else {
		printf("0\n");
	}
	return 0;
}