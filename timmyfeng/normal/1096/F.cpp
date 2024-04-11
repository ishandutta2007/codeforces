#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;
const int M = (119 << 23) + 1;

int ft[MX], inv[MX], con[MX], p[MX], a[MX], n;
bool seen[MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return ll(a) * b % M;
}

int qry(int a) {
	int res = 0;
	for ( ; a; a -= a & -a) {
		res += ft[a];
	}
	return res;
}

void upd(int a, int val) {
	for ( ; a <= n; a += a & -a) {
		ft[a] += val;
	}
}

void init() {
	inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		inv[i] = M - mul(M / i, inv[M % i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		if (p[i] != -1) {
			seen[p[i]] = true;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (seen[i]) {
			con[i] = cnt;
		} else {
			++cnt;
		}
	}

	int cur = 0;
	int ans = mul(cnt, mul(cnt - 1, inv[4]));
	int u = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] != -1) {
			cur = add(cur, mul(con[p[i]], inv[cnt]));
			ans = add(ans, mul(u, mul(cnt - con[p[i]], inv[cnt])));
			ans = add(ans, qry(n) - qry(p[i]));
			upd(p[i], 1);
		} else {
			ans = add(ans, cur);
			++u;
		}
	}
	cout << ans << '\n';
}