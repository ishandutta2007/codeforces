#include <bits/stdc++.h>

const int N = 400000;

int a[N + 5], n;
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[0] = a[n + 1] = 0;
	
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += std::max(0, a[i] - a[i - 1]) + std::max(0, a[i] - a[i + 1]);
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			ans -= a[i] - std::max(a[i - 1], a[i + 1]);
	}
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}