#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 4; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int m1 = min(a, b), m2 = min(c, d);
		if (m1 + m2 <= n) {
			printf("%d %d %d\n", i, m1, n - m1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}