#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = (119 << 23) + 1;
const int MX = 7500;

int fact[MX], invfact[MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return ll(a) * b % M;
}

int modpow(int b, int e) {
	if (!e)
		return 1;
	if (e % 2)
		return mul(b, modpow(b, e - 1));
	int tmp = modpow(b, e / 2);
	return mul(tmp, tmp);
}

int inv(int a) {
	return modpow(a, M - 2);
}

int cnk(int n, int k) {
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void init() {
	fact[0] = invfact[0] = invfact[1] = 1;
	for (int i = 2; i < MX; ++i) {
		invfact[i] = M - mul(M / i, invfact[M % i]);
	}
	for (int i = 1; i < MX; ++i) {
		invfact[i] = mul(invfact[i - 1], invfact[i]);
		fact[i] = mul(fact[i - 1], i);
	}
}

int calc(int g, int p, int t) {
	if (!p && !g)
		return 1;
	int res = 0;
	for (int i = 0, skip = 0; i <= p && skip <= g; ++i, skip += t + 1) {
		int val = mul(cnk(p, i), cnk(p - 1 + g - skip, p - 1));
		if (i % 2) {
			res = sub(res, val);
		} else {
			res = add(res, val);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int p, s, r;
	cin >> p >> s >> r;
	
	int ans = 0;
	for (int len = r; len <= s; ++len) {
		for (int cnt = 1; cnt <= p; ++cnt) {
			if (cnt * len > s)
				break;
			ans = add(ans, mul(cnk(p - 1, cnt - 1), mul(inv(cnt), calc(s - cnt * len, p - cnt, len - 1))));
		}
	}
	ans = mul(ans, inv(cnk(s - r + p - 1, p - 1)));
	cout << ans << '\n';
}