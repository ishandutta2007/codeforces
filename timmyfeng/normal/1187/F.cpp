#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int M = 1e9 + 7;
const int MX = 2e5;

ll l[MX + 1], r[MX + 1], rg[MX + 1], comp[MX + 1], prob[MX + 1];

ll modpow(ll a, ll b) {
	if (!b) return 1;
	if (b % 2) return a * modpow(a, b - 1) % M;
	ll tmp = modpow(a, b / 2);
	return tmp * tmp % M;
}

int getprob(int a) {
	int lb = max({l[a - 1], l[a], l[a + 1]});
	int ub = min({r[a - 1], r[a], r[a + 1]});
	int res = (comp[a] + comp[a + 1]) % M;
    res = (res - max(0, ub - lb + 1) * modpow(rg[a - 1] * rg[a] % M * rg[a + 1] % M, M - 2) % M + M) % M;
	return (1 - res + M) % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
		rg[i] = r[i] - l[i] + 1;
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		int lb = max(l[i], l[i - 1]);
		int ub = min(r[i], r[i - 1]);

		comp[i] = max(0, ub - lb + 1) * modpow(rg[i] * rg[i - 1] % M, M - 2) % M;
		prob[i] = (1 - comp[i] + M) % M;
		sum = (sum + prob[i]) % M;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = (ans + prob[i] * (sum - prob[i] + M)) % M;
		ans = (ans + prob[i]) % M;
		if (i > 1) {
			ans = (ans - prob[i] * prob[i - 1] % M + M) % M;
			ans = (ans + getprob(i - 1)) % M;
		}
		if (i < n) {
			ans = (ans - prob[i] * prob[i + 1] % M + M) % M;
			ans = (ans + getprob(i)) % M;
		}
	}
	cout << ans << '\n';
}