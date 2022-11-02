#include <bits/stdc++.h>

typedef long long ll;

void solve() {
	int n, x, t; scanf("%d%d%d", &n, &x, &t);
	if ((ll)n * x <= t) {
		printf("%lld\n", (ll)n * (n - 1) / 2);
	} else {
		int p = t / x;
		printf("%lld\n", (ll)n * p - (ll)p * (p + 1) / 2);
	}	
}

int main() {
	int k; scanf("%d", &k);
	while (k--) solve();
}