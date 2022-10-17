#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
inline ll read() {
	ll ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 500500, mod = 1e9 + 7;
int n; ll a[MAXN], buc[66], p2[66];

int main () {
	int T = read(); p2[0] = 1;
	for (int i = 1; i <= 60; i++) p2[i] = 2ll * p2[i - 1] % mod;
	while (T--) {
		n = read(); ll i, j, k;
		for (i = 0; i <= 60; i++) buc[i] = 0;
		for (i = 1; i <= n; i++) {
			a[i] = read();
			for (j = 0; j <= 60; j++)
				if ((a[i] >> j) & 1ll) ++buc[j];
		}
		ll ans = 0;
		for (j = 1; j <= n; j++) {
			ll A = 0, B = 0;
			for (i = 0; i <= 60; i++) {
				if (!((a[j] >> i) & 1ll)) continue;
				A = (A + 1ll * p2[i] * buc[i]) % mod;
			}
			for (i = 0; i <= 60; i++) {
				if (((a[j] >> i) & 1ll)) B = (B + 1ll * n * p2[i]) % mod;
				else B = (B + 1ll * p2[i] * buc[i]) % mod;
			}
			ans = (ans + A * B % mod) % mod;
		}
		printf("%lld\n", (ans + mod) % mod);
	}
	return 0;
}