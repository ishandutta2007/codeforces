#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	int ans = 0;
	for (int i = 0; i * a <= n; ++i) {
		for (int j = 0; j * b + i * a <= n; ++j) {
			int k = n - j * b - i * a;
			if (k % c == 0) {
				ans = max(ans, i + j + k / c);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}