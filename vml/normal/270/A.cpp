#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a;
		scanf("%d", &a);
		if (360 % (180 - a) == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}