#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

int mod_inv(int a) {
	return mod_pow(a, M - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.rbegin(), a.rend());

	for (int i = 1; i < n; ++i) {
		a[i] = add(a[i], a[i - 1]);
	}

	for (int k = 1; k <= n; ++k) {
		int ans = 0;
		for (int i = 0; i < n; i += k) {
			int sum = a[min(i + k - 1, n - 1)];
			sum = sub(sum, i ? a[i - 1] : 0);
			ans = add(ans, mul(i / k, sum));
		}
		ans = mul(ans, mod_inv(n));
		cout << ans << " ";
	}
	cout << "\n";
}