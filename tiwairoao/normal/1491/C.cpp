#include <bits/stdc++.h>

const int N = 5000;

int S[N + 5], a[N + 5], n;

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &S[i]), a[i] = 0;
	
	long long ans = 0, s = 0;
	for(int i=1;i<=n;i++) {
		a[i + 2]++, a[std::min(n + 1, i + S[i] + 1)]--;
		s += a[i];
		if( S[i] - 1 - s < 0 ) {
			a[i + 1] += s - (S[i] - 1);
			a[i + 2] -= s - (S[i] - 1);
		} else ans += std::max(0ll, S[i] - 1 - s);
	}
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}