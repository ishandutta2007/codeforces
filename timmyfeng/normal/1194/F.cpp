#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5;
const int M = 1e9 + 7;

int fact[MX + 1], invFact[MX + 1], invTwo[MX + 1], a[MX + 1];

int add(int a, int b) {
	return a + b >= M ? a + b - M : a + b;
}

int sub(int a, int b) {
	return a - b < 0 ? a - b + M : a - b;
}

int mul(int a, int b) {
	return (ll)a * b % M;
}

int comb(int n, int k) {
	if (k > n) return 0;
	return mul(fact[n], mul(invFact[n - k], invFact[k]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll t;
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(i, fact[i - 1]);
	}
	invFact[0] = invFact[1] = 1;
	for (int i = 2; i <= n; ++i) {
		invFact[i] = M - mul(M / i, invFact[M % i]);
	}
	for (int i = 1; i <= n; ++i) {
		invFact[i] = mul(invFact[i], invFact[i - 1]);
	}
	invTwo[1] = (M + 1) / 2;
	for (int i = 2; i <= n; ++i) {
		invTwo[i] = mul(invTwo[i - 1], invTwo[1]);
	}

	ll sum = 0;
	int ps = 1, ans = 0, cur = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
		int thr = min((ll)i, t - sum);
		if (thr < 0) break;

		ps = add(comb(i - 1, ++cur), add(ps, ps));
		for ( ; cur > thr; --cur) {
			ps = sub(ps, comb(i, cur));
		}
		ans = add(ans, mul(ps, invTwo[i]));
	}
	cout << ans << '\n';
}