#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n > m) {
		//010
		if (n > m + 1) {
			printf("-1\n");
		} else {
			printf("0");
			for (int i = 0; i < n - 1; ++i) {
				printf("10");
			}
		}
	} else if (n < m) {
		//101
		int g = m / (n + 1), k = (m + n) / (n + 1);
		if (k > 2) {
			printf("-1\n");
		} else {
			int c = m - (n + 1);
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				if (cnt < c) {
					printf("1");
					++cnt;
				}
				printf("10");
			}
			if (cnt < c) {
				printf("1");
			}
			printf("1");
		}
	} else {
		for (int i = 0; i < n; ++i) {
			printf("10");
		}
		printf("\n");
	}
	return 0;
}