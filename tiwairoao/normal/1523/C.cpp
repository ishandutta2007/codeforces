#include <bits/stdc++.h>

const int N = 1000;

int a[N + 5], n;

int stk[N + 5], tp;
void solve() {
	scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	tp = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			stk[++tp] = 1;
		} else {
			while (tp && a[i] != stk[tp] + 1) tp--; stk[tp]++;
		}
		assert (tp);
		for (int j = 1; j <= tp; j++)
			printf("%d%c", stk[j], j == tp ? '\n' : '.');
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}