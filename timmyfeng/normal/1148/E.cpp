#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	long long sum = 0;
	vector<pair<int, int>> stones;
	for (int i = 1; i <= n; ++i) {
		int s;
		cin >> s;
		stones.emplace_back(s, i);
		sum += s;
	}
	sort(stones.begin(), stones.end());

	vector<int> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		sum -= t[i];
	}
	sort(t.begin(), t.end());

	if (sum) {
		cout << "NO\n";
		return 0;
	}

	int j = 0;
	vector<tuple<int, int, int>> ans;
	for (int i = 0; i < n; ++i) {
		if (stones[i].first > t[i]) {
			cout << "NO\n";
			return 0;
		}

		while (stones[i].first < t[i]) {
			while (j < n && stones[j].first <= t[j]) {
				++j;
			}

			int d = min(t[i] - stones[i].first, stones[j].first - t[j]);
			ans.emplace_back(stones[i].second, stones[j].second, d);
			stones[i].first += d;
			stones[j].first -= d;
		}
	}

	cout << "YES\n";
	cout << ans.size() << "\n";
	for (auto [u, v, d] : ans) {
		cout << u << " " << v << " " << d << "\n";
	}	
}