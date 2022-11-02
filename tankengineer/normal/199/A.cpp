#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a = 0, b = 1, c = 1, n;
	scanf("%d", &n);
	if (n == 0) {
		printf("0 0 0\n");
	} else {
		while (c != n) {
			a = b;
			b = c;
			c = a + b;
		}
		printf("%d %d %d\n", a, b, 0);
	}
	return 0;
}