#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int mul(int a, int b) {
	return (long long)a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}

	vector<int> suf_mn(n + 1, 1e9 + 1);
	for (int i = n - 1; i >= 0; --i) {
		suf_mn[i] = min(suf_mn[i + 1], a[i]);
	}

	if (suf_mn[0] != b[0]) {
		cout << 0 << '\n';
		return 0;
	}

	int ans = 1;
	for (int i = 1; i < m; ++i) {
		auto it_l = lower_bound(suf_mn.begin(), suf_mn.end(), b[i]);
		auto it_r = upper_bound(suf_mn.begin(), suf_mn.end(), b[i]);
		ans = mul(ans, it_r - it_l);
	}
	cout << ans << '\n';
}