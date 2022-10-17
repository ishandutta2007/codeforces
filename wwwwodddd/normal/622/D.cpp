#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	for (int i = n - 1 - n % 2; i >= 1; i -= 2) {
		printf("%d ", n - i);
	}
	for (int i = 1; i < n; i += 2) {
		printf("%d ", n - i);
	}
	for (int i = n - (n + 1) % 2 - 1; i >= 2; i -= 2) {
		printf("%d ", n - i);
	}
	printf("%d ", n);
	for (int i = 2; i < n; i += 2) {
		printf("%d ", n - i);
	}
	printf("%d\n", n);
}