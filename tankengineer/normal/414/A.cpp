#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 1) {
		if (k == 0) {
			printf("1\n");
			return 0;
		} else {
			printf("-1\n");
			return 0;
		}
	}
	if (n / 2 > k) {
		printf("%d\n", -1);
		return 0;
	}
	int t = n / 2 - 1;
	for (int i = 0; i < t; ++i) {
		printf("%d %d ", i * 2 + 1, i * 2 + 2);
	}
	int last = t * 2, left = k - t;
	printf("%d %d", (last / left + 1) * left, (last / left + 2) * left);
	if (n % 2 == 1) {
		printf(" 1000000000");
	}
	printf("\n");
	return 0;
}