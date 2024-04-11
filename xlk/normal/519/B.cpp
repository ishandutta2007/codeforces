#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a ^= x;
	}
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		b ^= x;
	}
	for (int i = 2; i < n; i++) {
		scanf("%d", &x);
		c ^= x;
	}
	printf("%d\n%d\n", a ^ b, b ^ c);
	return 0;
}