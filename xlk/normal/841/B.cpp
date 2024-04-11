#include <bits/stdc++.h>
using namespace std;
int n, x, odd;
long long s;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x % 2 == 1) {
			odd = 1;
		}
		s += x;
	}
	if (s % 2 == 1) {
		printf("First\n");
	} else {
		if (odd) {
			printf("First\n");
		} else {
			printf("Second\n");
		}
	}
	return 0;
}