#include <bits/stdc++.h>
using namespace std;
int n, m, sum, ans;
int r[105], c[105], rr[105], cc[105], g[105][105], a[105][105];
bool flag = true;
int work1() {
	for (int j = 1; j <= m; ++j) {
		c[j] = 1005;
		for (int i = 1; i <= n; ++i) 
			c[j] = min(c[j], g[i][j]);
		for (int i = 1; i <= n; ++i) 
			a[i][j] = g[i][j] - c[j];
	}
	
	for (int i = 1; i <= n; ++i) {
		r[i] = a[i][1];
		for (int j = 1; j <= m; ++j)
			if (a[i][j] != r[i]) {
				flag = false;
			}
	}
	
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += r[i];
	for (int j = 1; j <= m; ++j)
		sum += c[j];
	return sum;
}
int work2() {
	for (int i = 1; i <= n; ++i) {
		r[i] = 1005;
		for (int j = 1; j <= m; ++j) 
			r[i] = min(r[i], g[i][j]);
		for (int j = 1; j <= m; ++j) 
			a[i][j] = g[i][j] - r[i];
	}
	
	for (int j = 1; j <= m; ++j) {
		c[j] = a[1][j];
		for (int i = 1; i <= n; ++i)
			if (a[i][j] != c[j]) {
				flag = false;
			}
	}
	
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += r[i];
	for (int j = 1; j <= m; ++j)
		sum += c[j];
	return sum;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			scanf("%d", &g[i][j]);
	
	ans = work1();
	int ret = work2();
	if (ret > ans) work1();
	else ans = ret;
	
	if (flag) {
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i) {
			for (int k = 1; k <= r[i]; ++k) {
				printf("row %d\n", i);
			}
		}
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= c[j]; ++k) {
				printf("col %d\n", j);
			}
		}
	}
	else puts("-1");
}