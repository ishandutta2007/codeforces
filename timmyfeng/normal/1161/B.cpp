#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

const int M = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> hsh(n);
	for (int i = 0; i < n; ++i) {
		hsh[i] = uniform_int_distribution<int>(0, M - 1)(rng);
	}

	int og = 0;
	vector<pair<int, int>> segments(m);
	for (auto& [a, b] : segments) {
		cin >> a >> b;
		--a, --b;
		og ^= 1LL * hsh[a] * hsh[b] % M;
	}

	bool ok = false;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			int res = 0;
			for (auto [a, b] : segments) {
				int c = (a + i) % n;
				int d = (b + i) % n;
				res ^= 1LL * hsh[c] * hsh[d] % M;
			}
			ok |= res == og;
		}
	}
	cout << (ok ? "Yes" : "No") << "\n";
}