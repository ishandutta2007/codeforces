#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, d, h;
	scanf("%d%d%d", &n, &d, &h);
	if (d == h) {
		if (h == 1) {
			if (n == 2) {
				printf("%d %d\n", 1, 2);
			} else {
				puts("-1");
			}
		} else {
			for (int i = 1; i <= h; ++i) {
				printf("%d %d\n", i, i + 1);
			}
			for (int i = h + 1; i < n; ++i) {
				printf("%d %d\n", 2, i + 1);
			}
		}
	} else {
		if (d <= 2 * h) {
			for (int i = 1; i <= h; ++i) {
				printf("%d %d\n", i, i + 1);
			}
			printf("%d %d\n", 1, h + 2);
			for (int i = h + 2; i < d + 1; ++i) {
				printf("%d %d\n", i, i + 1);
			}
			for (int i = d + 1; i < n; ++i) {
				printf("%d %d\n", 1, i + 1);
			}
		} else {
			puts("-1");
		}
	}
	return 0;
}