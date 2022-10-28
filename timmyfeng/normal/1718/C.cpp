#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n, q; cin >> n >> q;

		vector<vector<long long>> rings;
		int temp = n;
		for (int i = 2; i <= temp; ++i) {
			if (temp % i == 0) {
				rings.emplace_back(n / i);
				while (temp % i == 0) temp /= i;
			}
		}

		priority_queue<array<long long, 3>> values;
		vector<long long> a(n);

		auto update = [&](int p, int x) {
			for (int i = 0; i < (int) rings.size(); ++i) {
				auto &r = rings[i];
				r[p % r.size()] += x - a[p];
				values.push({r.size() * r[p % r.size()], i, p % r.size()});
			}
			a[p] = x;
		};

		auto query = [&]() {
			while (true) {
				auto [x, i, j] = values.top();
				if (rings[i][j] == x / rings[i].size()) return x;
				values.pop();
			}
		};

		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			update(i, x);
		}

		cout << query() << "\n";

		for (int i = 0; i < q; ++i) {
			int p, x; cin >> p >> x;
			update(p - 1, x);
			cout << query() << "\n";
		}
	}
}