#include <bits/stdc++.h>

const int N = 400000;
const int P = int(1E9) + 7;

bool vis[N + 5]; int p[N + 5], a[N + 5], b[N + 5], n;
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) p[a[i]] = b[i], vis[i] = false;

	int ans = 1;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		int x = i;
		do {
			vis[x] = true, x = p[x];
		} while (x != i);
		ans <<= 1; if (ans >= P) ans -= P;
	}
	printf("%d\n", ans);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) solve();

}