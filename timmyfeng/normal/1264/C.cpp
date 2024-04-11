#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;
const int M = (119 << 23) + 1;

int p[MX], pre_prod[MX], pre_prod_sum[MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int mod_pow(int b, int e) {
	int res = 1;
	while (e) {
		if (e % 2) {
			res = mul(res, b);
		}
		b = mul(b, b);
		e /= 2;
	}
	return res;
}

int mod_inv(int a) {
	return mod_pow(a, M - 2);
}

int calc(int a, int b) {
	int num = add(mul(sub(pre_prod_sum[b - 1], pre_prod_sum[a - 1]), mod_inv(pre_prod[a - 1])), 1);
	int den = mul(pre_prod[b], mod_inv(pre_prod[a - 1]));
	return mul(num, mod_inv(den));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		p[i] = mul(p[i], mod_inv(100));
	}

	pre_prod[0] = 1;
	pre_prod_sum[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pre_prod[i] = mul(pre_prod[i - 1], p[i]);
		pre_prod_sum[i] = add(pre_prod_sum[i - 1], pre_prod[i]);
	}

	set<int> pts = {1, n + 1};
	int ans = calc(1, n);

	while (q--) {
		int u;
		cin >> u;

		if (pts.count(u)) {
			auto it = pts.find(u);
			ans = sub(ans, calc(*prev(it), *it - 1));
			ans = sub(ans, calc(*it, *next(it) - 1));
			ans = add(ans, calc(*prev(it), *next(it) - 1));
			pts.erase(it);
		} else {
			auto it = pts.insert(u).first;
			ans = sub(ans, calc(*prev(it), *next(it) - 1));
			ans = add(ans, calc(*it, *next(it) - 1));
			ans = add(ans, calc(*prev(it), *it - 1));
		}
		cout << ans << "\n";
	}
}