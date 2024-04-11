#include <bits/stdc++.h>

int w[105], n, x;

void solve() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]), w[i] += w[i - 1];
	
	if (w[n] == x) {
		puts("NO");
	} else {
		puts("YES");
		for (int i = 1; i <= n; i++) {
			if (w[i] == x) {
				printf("%d %d ", w[i + 1] - w[i], w[i] - w[i - 1]), i++;
			} else {
				printf("%d ", w[i] - w[i - 1]);
			}
		}
		puts("");
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}