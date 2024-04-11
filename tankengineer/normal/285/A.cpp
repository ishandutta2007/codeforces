#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = n; i > n - k; --i) {
		printf("%d%c", i, i == 1 ? '\n' : ' ');
	}
	for (int i = 1; i <= n - k; ++i) {
		printf("%d%c", i, i == n - k ? '\n' : ' ');
	}
	return 0;
}