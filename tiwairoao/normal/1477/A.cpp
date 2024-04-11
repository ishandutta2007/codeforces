#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;

int n; ll x[N + 5], k;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve() {
	ll d = 0; scanf("%d%lld", &n, &k);
	for(int i=1;i<=n;i++) scanf("%lld", &x[i]);
	std::sort(x + 1, x + n + 1);
	for(int i=2;i<=n;i++) d = gcd(d, x[i] - x[i - 1]);
	d = (d < 0 ? -d : d);
	puts((k - x[1]) % d == 0 ? "YES" : "NO");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}