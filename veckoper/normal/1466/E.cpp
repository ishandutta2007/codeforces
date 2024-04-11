#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
const int p = 1e9 + 7;
int Case, n, sm[60];
int a[N];
signed main() {
	scanf("%lld", &Case);
	while (Case--) {
		scanf("%lld", &n);
		memset(sm, 0, sizeof sm);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			for (int j = 0; j < 60; ++j) if (a[i] >> j & 1) sm[j] = (sm[j] + (1ll << j)) % p;
		}
		int ans = 0;
		for (int k = 1; k <= n; ++k) {
			int vor = 0, vand = 0;
			for (int i = 0; i < 60; ++i) {
				if (a[k] >> i & 1) {
					vor += n * ((1ll << i) % p) % p;
					vand += sm[i];
				} else {
					vor += sm[i];
				}
			}
			ans = (ans + (vor % p) * (vand % p)) % p;
		}
		if (ans < 0) ans += p;
		printf("%lld\n", ans);
	}
	return 0;
}