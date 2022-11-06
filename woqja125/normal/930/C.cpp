#include<cstdio>
#include<algorithm>
using namespace std;
int c[100011];
int x[100001];
int y[100001];
int t[100001];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		c[l]++; c[r + 1]--;
	}
	for (int i = 1; i <= m; i++) c[i] += c[i - 1];
	for (int i = 0; i <= m; i++) t[i] = 1000000;
	for (int i = 1; i <= m; i++) {
		auto it = upper_bound(t+1, t + m + 1, c[i]);
		x[i] = it - t;
		*it = c[i];
	}
	for (int i = 0; i <= m; i++) t[i] = 1000000;
	for (int i = m; i >= 1; i--) {
		auto it = upper_bound(t + 1, t + m + 1, c[i]);
		y[i] = it - t;
		*it = c[i];
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (ans < x[i] + y[i] - 1) ans = x[i] + y[i] - 1;
	}
	printf("%d\n", ans);
	return 0;
}