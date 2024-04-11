#include <bits/stdc++.h>

typedef long long ll;

const ll INF = (1ll << 61);
const int N = 1000000;

ll a[N + 5], f[3][N + 5], r1, r2, r3, d; int n;

int main() {
	scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	
	f[0][0] = -d, f[1][0] = f[2][0] = INF;
	for(int i=1;i<=n;i++) {
		ll p = a[i] * r1 + r3;
		ll q = std::min(p, std::min(r1 + r2, (a[i] + 2) * r1));
		
		f[0][i] = f[1][i] = f[2][i] = INF;
		f[0][i] = std::min(f[0][i], f[0][i - 1] + p + d);
		f[0][i] = std::min(f[0][i], f[2][i - 1] + q + 3*d);
		if( i != n ) {
			f[1][i] = std::min(f[1][i], f[0][i - 1] + q + d);
			f[1][i] = std::min(f[1][i], f[1][i - 1] + q + 2*d);
			f[2][i] = std::min(f[2][i], f[0][i - 1] + q + d);
			f[2][i] = std::min(f[2][i], f[2][i - 1] + q + 3*d);
		} else {
			f[1][i] = std::min(f[1][i], f[1][i - 1] + p + 2*d);
			f[2][i] = std::min(f[2][i], f[2][i - 1] + q + 3*d);
		}
		
	}
	printf("%lld\n", std::min(f[0][n], f[1][n]));
}