#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n % 3 == 0) {
			for (int i = 0; i < n / 3; ++i) {
				printf("21");
			}
			printf("\n");
		} else if (n % 3 == 1) {
			printf("1");
			for (int i = 0; i < n / 3; ++i) {
				printf("21");
			}
			printf("\n");
		} else {
			printf("2");
			for (int i = 0; i < n / 3; ++i) {
				printf("12");
			}
			printf("\n");
		}
	}
	return 0;
}