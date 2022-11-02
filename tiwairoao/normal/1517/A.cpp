#include <bits/stdc++.h>

typedef long long ll;

int solve(ll n) {
	int x = 0;
	while (n) x += (n % 10), n /= 10;
	return x;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		ll n; scanf("%lld", &n);
		if (n % 2050) puts("-1");
		else printf("%d\n", solve(n / 2050));
	}
}