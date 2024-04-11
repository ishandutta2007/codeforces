#include <bits/stdc++.h>
using namespace std;
const int MOD = (119 << 23) + 1;

long long modPow(long long b, long long e) {
	if (!e) return 1;
	if (e % 2) return b * modPow(b, e - 1) % MOD;
	long long tmp = modPow(b, e / 2);
	return tmp * tmp % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, m, l, r;
	cin >> n >> m >> l >> r;
	long long ans = modPow(r - l + 1, n * m);
	if (n * m % 2) {
		cout << ans << '\n'; 
	} else {
		if ((r - l + 1) % 2) {
			(ans += 1) %= MOD;
		}
		cout << ans * modPow(2, MOD - 2) % MOD << '\n';
	}
}