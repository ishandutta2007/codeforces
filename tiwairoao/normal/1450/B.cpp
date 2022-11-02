#include <bits/stdc++.h>

int x[105], y[105], n, k;
bool check(int i) {
	for (int j = 1; j <= n; j++) if (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) > k)
		return false;
	return true;
}
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) if (check(i)) {puts("1"); return;}
	puts("-1");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
}