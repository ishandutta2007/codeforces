#include <iostream>
#include <cstdio>
using namespace std;
int m, s;
int a[10], c;
int main() {
	scanf("%d", &m);
	for (int i = 1; i <= 5 * m + 5; i++) {
		int t = i;
		while (t % 5 == 0) {
			t /= 5;
			s += 1;
		}
		if (s == m) {
			a[c++] = i;
		} else if (s > m) {
			break;
		}
	}
	printf("%d\n", c);
	for (int i = 0; i < c; i++) {
		printf("%d%c", a[i], i == c - 1 ? '\n': ' ');
	}
	return 0;
}