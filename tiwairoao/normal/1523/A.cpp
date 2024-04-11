#include <bits/stdc++.h>

const int N = 1000;

int b[N + 5], c[N + 5], n, m;

char s[N + 5];
void solve() {
	scanf("%d%d%s", &n, &m, s + 1);

	for (int i = 1, j = -(1 << 30); i <= n; i++) {
		if (s[i] == '1') j = i;
		b[i] = i - j;
	}
	for (int i = n, j = (1 << 30); i >= 1; i--) {
		if (s[i] == '1') j = i;
		c[i] = j - i;
	}

	for (int i = 1; i <= n; i++) {
		if (b[i] == c[i] && b[i]) putchar('0');
		else if (std::min(b[i], c[i]) > m) putchar('0');
		else putchar('1');
	}
	puts("");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}