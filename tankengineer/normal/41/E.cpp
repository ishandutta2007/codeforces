#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n / 2 * ((n + 1) / 2));
	for (int i = 1; i <= n; i += 2) {
		for (int j = 2; j <= n; j += 2) {
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}