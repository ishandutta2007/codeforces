#include <bits/stdc++.h>

typedef long long ll;

ll solve(ll a, ll b, ll c, ll d) {
	if( b * c < a ) return -1;
	else {
		ll n = (a + b * d - 1) / (b * d) - 1;
		return a * (n + 1) - n * (n + 1) / 2 * b * d;
	}
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%lld\n", solve(a, b, c, d));
	}
}