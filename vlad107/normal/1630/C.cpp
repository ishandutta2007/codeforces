#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <array>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> rngInp(n, {n, -1});
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		--x;
		if (rngInp[x].first == n) rngInp[x].first = i;
		rngInp[x].second = i;
	}
	vector<pair<int, int>> rng;
	for (auto &[l, r] : rngInp) {
		if (l < r) {
			rng.push_back({l, r});
		}
	}
	sort(rng.begin(), rng.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
		if (lhs.first != rhs.first) return lhs.first < rhs.first;
		return lhs.second > rhs.second;
	});

	vector<pair<int, int>> rng2;
	for (int i = 0; i < rng.size(); i++) {
		if ((!rng2.empty()) && (rng[i].second <= rng2.back().second)) continue;
		rng2.push_back(rng[i]);
	}
	rng = rng2;
	
	int ans = 0;
	for (int i = 0; i < rng.size(); i++) {
		int j = i;
		int cnt = 1;
		while (1) {
			pair<int, int> val(rng[j].second, 0);
			auto it = upper_bound(rng.begin(), rng.end(), val);
			int nj = it - rng.begin() - 1;
			if (nj == j) break;
			++cnt;
			j = nj;
		}
		ans += rng[j].second - rng[i].first - cnt;
		i = j;
	}
	cout << ans << endl;

	return 0;
}