#include <bits/stdc++.h>
using namespace std;
int main() {
	int q, x;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		int b = 1;
		while (b <= x) {
			b *= 2;
		}
		if (b - 1 == x) {
			for (int i = 2; i <= x; i++) {
				if (x % i == 0) {
					printf("%d\n", x / i);
					break;
				}
				if (i * i > x) {
					printf("%d\n", 1);
					break;
				}
			}
		} else {
			printf("%d\n", b - 1);
		}
	}
}