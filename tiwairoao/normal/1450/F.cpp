#include <bits/stdc++.h>

const int N = 100000;

int a[N + 5], b[N + 5], n;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) b[i] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]]++;
	for (int i = 1; i <= n; i++) if ((b[i] << 1) > n + 1) {
		puts("-1"); return;
	}
	
	int tmp = 0;
	for (int i = 1; i <= n; i++) b[i] = 0; b[a[1]]++, b[a[n]]++;
	for (int i = 2; i <= n; i++) if (a[i - 1] == a[i]) tmp++, b[a[i - 1]]++, b[a[i]]++;
	int mx = *std::max_element(b + 1, b + n + 1);
	printf("%d\n", std::max(tmp, mx - 2));
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}