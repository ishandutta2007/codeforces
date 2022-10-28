#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, m, x, k, y;
	cin >> n >> m >> x >> k >> y;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<int> b(m);
	for (auto& i : b) {
		cin >> i;
	}

	int mx = 0;
	int ptr = 0;
	int cur = 0;
	int pre = 0;
	long long ans = 0;

	auto proc = [&](int i) {
		long long res = 1e18;
		if (mx < i || mx < pre) {
			res = 1LL * y * cur;
		}
		if (cur >= k) {
			res = min(res, x + min((cur / k - 1) * x + (cur % k) * y, (cur - k) * y));
		}
		if (res == 1e18) {
			cout << -1 << "\n";
			exit(0);
		}
		ans += res;
	};

	for (int i = 0; i < n; ++i) {
		if (ptr < m && a[i] == b[ptr]) {
			proc(a[i]);
			pre = a[i];
			cur = 0;
			mx = 0;
			++ptr;
		} else {
			mx = max(mx, a[i]);
			++cur;
		}
	}
	proc(0);

	if (ptr != m) {
		cout << -1 << "\n";
		exit(0);
	}

	cout << ans << "\n";
}