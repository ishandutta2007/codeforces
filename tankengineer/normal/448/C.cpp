#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005;

int n;
int a[N];

int f[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			f[i][j] = n + 1;
		}
	}
	a[n] = n;
	f[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n && j <= a[i]; ++j) {
			if (j + 1 <= n && j + 1 <= a[i]) {
				f[i][j + 1] = min(f[i][j + 1], f[i][j] + 1);
			}
			int tr = min(j, a[i + 1]);
			f[i + 1][tr] = min(f[i + 1][tr], f[i][j] + (j != a[i]));
		}
	}
	int ans = n;
	for (int i = 0; i <= n && i <= a[n - 1]; ++i) {
		ans = min(ans, f[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}