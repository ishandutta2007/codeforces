#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int s1, s2, s3;
	scanf("%d %d %d", &s1, &s2, &s3);
	for (int a = 1; a <= s1; a++) {
		if (s1 % a == 0) {
			int b = s1 / a;
			if (s2 % b == 0) {
				int c = s2 / b;
				if (s3 == c * a) {
					printf("%d", 4 * (a + b + c));
					exit(0);
				}
			}
		}
	}
	return 0;
}