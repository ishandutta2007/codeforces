#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for (auto& i : a) {
			cin >> i;
		}
		for (auto& i : b) {
			cin >> i;
		}
		rotate(b.begin(), b.end() - 1, b.end());

		bool ok = accumulate(b.begin(), b.end(), 0LL) >= accumulate(a.begin(), a.end(), 0LL);

		long long cur = 0;
		for (int i = 0; i < 2 * n; ++i) {
			ok &= cur + b[i % n] >= 0;
			cur = min(cur + b[i % n] - a[i % n], 0LL + b[i % n] - a[i % n]);	
		}

		cout << (ok ? "YES" : "NO") << "\n";
	}
}