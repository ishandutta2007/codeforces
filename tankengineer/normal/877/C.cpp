#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n + n / 2);
	for (int i = 1; i < n; i += 2) {
		printf("%d%c", i + 1, ' ');
	}
	for (int i = 0; i < n; i += 2) {
		printf("%d%c", i + 1, ' ');
	}
	for (int i = 1; i < n; i += 2) {
		printf("%d%c", i + 1, ' ');
	}
	printf("\n");
	return 0;
}