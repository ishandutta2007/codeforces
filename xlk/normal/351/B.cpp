#include <stdio.h>
#include <iostream>
using namespace std;
int z, n, a[3020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j]) {
				z++;
			}
		}
	}
	printf("%d\n", z * 2 - z % 2);
	return 0;
}