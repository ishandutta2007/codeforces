#include <bits/stdc++.h>

const int N = 200000;

int a[N + 5], n, l, r;

void solve() {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++) a[i] = 0;
	for (int i = 1, x; i <= l; i++) scanf("%d", &x), a[x]++;
	for (int i = 1, x; i <= r; i++) scanf("%d", &x), a[x]--;

	int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 0) {
			r1 += a[i];
			if (a[i] & 1) l1++;
		} else {
			r2 -= a[i];
			if (a[i] & 1) l2++;
		}
	}

	int ans = (r1 + r2) >> 1;
	if (r1 > r2) std::swap(l1, l2), std::swap(r1, r2); // r1 <= r2
	if (r1 < l2) ans += (l2 - r1) >> 1;
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}