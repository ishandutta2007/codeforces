#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int pw(int x, int y, int p) {
	int z = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			z = (long long)z * x % p;
		}
		x = (long long)x * x % p;
	}
	return z;
}
int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("YES\n");
		printf("1\n");
		return 0;
	} else if(n == 4) {
		printf("YES\n");
		printf("1\n3\n2\n4\n");
		return 0;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	printf("1\n");
	for (int i = 2; i < n; i++) {
		printf("%d\n", (long long)i * pw(i - 1, n - 2, n) % n);
	}
	printf("%d\n", n);
	return 0;
}