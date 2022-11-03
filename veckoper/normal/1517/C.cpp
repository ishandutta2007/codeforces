#include <bits/stdc++.h>
using namespace std;
const int N = 502;
int n, a[N][N], c[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i][i]);
	}
	for (int i = 2; i <= n; ++i) {
		int tot = 0;
		for (int j = i - 1; j <= n; ++j) if (a[j][j - i + 2] != i - 1) {
			c[++tot] = a[j][j - i + 2];
		}
		for (int j = i; j <= n; ++j) a[j][j - i + 1] = c[j - i + 1];
	}
	for (int i = 1; i <= n; puts(""), ++i)
		for (int j = 1; j <= i; ++j)
			printf("%d ", a[i][j]);
	return 0;
}