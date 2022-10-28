#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

void solve() {
	int n, m, c, c0;
	cin >> n >> m >> c >> c0;
	vector<tuple<int, int, int>> ppl(n);
	for (auto& [t, a, b] : ppl) {
		cin >> t >> a >> b;
	}
	sort(ppl.begin(), ppl.end());
	ppl.emplace_back(m, 0, 1e9);

	multiset<pair<int, int>> cheap;
	int cur = 0, cap = c0;
	cheap.emplace(0, c0);
	ll ans = 0;
	for (auto [t, a, b] : ppl) {
		int delta = t - cur;
		while (delta) {
			if (cheap.empty()) {
				cout << -1 << '\n';
				return;
			}

			auto [p, q] = *cheap.begin();
			cheap.erase(cheap.begin());
			if (q >= delta) {
				ans += (ll)p * delta;
				cheap.emplace(p, q - delta);
				cap -= delta;
				delta = 0;
			} else {
				ans += (ll)p * q;
				delta -= q;
				cap -= q;
			}
		}

		cheap.emplace(b, a);
		cap += a;
		while (cap > c) {
			auto [p, q] = *cheap.rbegin();
			cheap.erase(--cheap.end());
			if (cap - q >= c) {
				cap -= q;
			} else {
				cheap.emplace(p, q - (cap - c));
				cap = c;
			}
		}
		cur = t;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}