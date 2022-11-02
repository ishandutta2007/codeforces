#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (k == 1 && n != 1 || k > n) {
		printf("-1");
	} else {
		if (k == 1) {
			printf("a");
		} else {
			int len = n - (k - 2);
			for (int i = 1; i <= len; i++) {
				printf("%c", (char)('a' + (i + 1) % 2));
			}
			for (int i = 3; i <= k; i++) {
				printf("%c", (char)('a' + i - 1));
			}
		}
	}
}