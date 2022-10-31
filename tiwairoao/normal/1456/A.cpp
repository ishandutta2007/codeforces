#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

char a[N + 5]; int n, p, k, x, y;

void solve() {
	scanf("%d%d%d%s%d%d", &n, &p, &k, a + 1, &x, &y);

	ll ans = (1ll << 60);
	for(int i=n;i>=1;i--) {
		if( i + k <= n ) break;
		for(int j=i,cnt=0;j>=p;j-=k) {
			cnt += (a[j] == '0');
			ans = std::min(ans, 1ll * (j - p) * y + 1ll * cnt * x);
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}