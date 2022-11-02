#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				printf("%d%c", i * 2 + 1, ' ');
			} else {
				printf("%d%c", i * 2 + 2, ' ');
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				printf("%d%c", i * 2 + 2, i == n - 1 ? '\n' : ' ');
			} else {
				printf("%d%c", i * 2 + 1, i == n - 1 ? '\n' : ' ');
			}
		}
	} else {
		printf("NO\n");
	}
	return 0;
}