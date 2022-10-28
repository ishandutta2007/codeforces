#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, h, m, k;
	cin >> n >> h >> m >> k;

	vector<pair<int, int>> trains;
	for (int i = 1; i <= n; ++i) {
		int hi, mi;
		cin >> hi >> mi;
		trains.emplace_back(mi % (m / 2), i);
		trains.emplace_back(mi % (m / 2) + m / 2, i);
	}
	sort(trains.begin(), trains.end());

	auto query = [&trains](int a) {
		return lower_bound(trains.begin(), trains.end(), make_pair(a, 0)) - trains.begin();
	};

	int ans_t = 0;
	int ans_cnt = n;
	for (auto [t, i] : trains) {
		if (t < m / 2)
			continue;
		int res = query(t) - query(t - k + 1);
		if (res < ans_cnt) {
			ans_cnt = res;
			ans_t = t;
		}
	}

	cout << ans_cnt << " " << ans_t - m / 2 << "\n";
	for (auto [t, i] : trains) {
		if (t > ans_t - k && t < ans_t) {
			cout << i << " ";
		}
	}
	cout << "\n";
}