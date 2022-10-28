#include <bits/stdc++.h> 
using namespace std;

void solve() {
	string s;
	cin >> s;
	map<char, int> mp;
	for (auto i : s) {
		++mp[i];
	}
	vector<pair<char, int>> all;
	for (auto i : mp) {
		all.push_back(i);
	}
	vector<pair<char, int>> ans;
	int n = all.size();
	if (n == 3) {
		if (abs(all[1].first - all[0].first) < abs(all[2].first - all[1].first)) {
			swap(all[0], all[2]);
		}
	}
	for (int i = 0; i < n / 2; ++i) {
		ans.push_back(all[i + n / 2]);
		ans.push_back(all[i]);
	}
	if (n % 2) {
		ans.push_back(all[n - 1]);
	}
	for (int i = 1; i < n; ++i) {
		if (abs(ans[i].first - ans[i - 1].first) == 1) {
			cout << "No answer" << '\n';
			return;
		}
	}
	for (auto [a, b] : ans) {
		cout << string(b, a);
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		solve();
	}
}