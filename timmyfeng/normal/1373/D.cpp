#include <bits/stdc++.h>
using namespace std;

long long calc(vector<int> a) {
	long long res = 0;
	long long cur = 0;
	for (int i = 0; i < int(a.size()); ++i) {
		cur = max(cur + a[i], 1LL * a[i]);
		res = max(res, cur);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		long long ans = 0;
		for (int i = 0; i < n; i += 2) {
			ans += a[i];
		}

		vector<int> b;
		for (int i = 1; i + 1 < n; i += 2) {
			b.push_back(a[i] - a[i + 1]);
		}

		vector<int> c;
		for (int i = 0; i + 1 < n; i += 2) {
			c.push_back(a[i + 1] - a[i]);
		}

		ans = max(ans, ans + max(calc(b), calc(c)));
		cout << ans << "\n";
	}
}