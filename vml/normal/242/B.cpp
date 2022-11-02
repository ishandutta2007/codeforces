#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int num, min_left = 1 << 30, min_right, max_right = 0;
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < min_left || a == min_left && b > min_right) {
			min_left = a;
			min_right = b;
			num = i;
		}
		max_right = max(max_right, b);
	}
	if (min_right >= max_right) {
		printf("%d", num);
	} else {
		printf("-1");
	}
	return 0;
}