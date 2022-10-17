#include <cstdio>

int f[100020];
int a[100020];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		f[i] = i;
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i * m + j]);
		}
	}
	for (int j = 0; j < m; j++) {
		int l = 0;
		for (int i = 1; i < n; i++) {
			if (a[i * m + j] < a[(i - 1) * m + j]) {
				l = i;
			}
			if (f[i] > l) {
				f[i] = l;
			} 
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		puts(f[r] <= l ? "Yes" : "No");
	}
	return 0;
}