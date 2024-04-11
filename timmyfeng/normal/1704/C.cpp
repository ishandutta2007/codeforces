#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;

		vector<int> a(m);
		for (auto &i : a) cin >> i;
		sort(a.begin(), a.end());

		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < m; ++i) {
			int len = (a[(i + 1) % m] - a[i] + n - 1) % n;
			if (len) pq.push({(len + 1) / 2, len});
		}

		int answer = n, days = 0;
		while (!pq.empty()) {
			auto [x, y] = pq.top();
			pq.pop();

			if (x == y) {
				if (days < y) {
					answer -= y - days;
					++days;
				}
			} else {
				if (days < x) {
					pq.push({y - days - 1, y - days - 1});
					--answer, ++days;
				}
			}
		}

		cout << answer << "\n";
	}
}