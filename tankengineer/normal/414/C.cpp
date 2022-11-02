#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
int n, a[1 << N], b[1 << N], tmp[1 << N];
long long rev[N + 1], inv[N + 1];

void merge(int l, int r, int d) {
	if (l == r) {
		return;
	}
	int m = l + r >> 1;
	merge(l, m, d + 1);
	merge(m + 1, r, d + 1);
	int i = l, j = m + 1, top = 0;
	while (i <= m && j <= r) {
		if (a[i] <= a[j]) {
			tmp[top++] = a[i++];
		} else {
			tmp[top++] = a[j++];
			rev[d] += (m - i + 1);
		}
	}
	while (i <= m) {
		tmp[top++] = a[i++];
	}
	while (j <= r) {
		tmp[top++] = a[j++];
	}
	for (int k = 0; k < top; ++k) {
		a[l + k] = tmp[k];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < (1 << n); ++i) {
		scanf("%d", a + i);
		b[i] = a[i];
	}
	merge(0, (1 << n) - 1, 0);
	for (int i = 0; i < n; ++i) {
		inv[i] = rev[i];
		rev[i] = 0;
	}
	for (int i = 0; i < (1 << n); ++i) {
		a[i] = b[(1 << n) - i - 1];
	}
	merge(0, (1 << n) - 1, 0);
	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		swap(rev[i], inv[i]);
		ans += rev[i];
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int r;
		scanf("%d", &r);
		r = n - r;
		for (int j = r; j <= n; ++j) {
			ans -= rev[j];
			swap(rev[j], inv[j]);
			ans += rev[j];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}