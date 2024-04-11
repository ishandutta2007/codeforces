#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n & 1) {
		printf("-1\n");
	} else {
		for (int i = 0; i < n; ++i) {
			printf("%d%c", 2 * (i / 2 + 1) - i % 2, i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}