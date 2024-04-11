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

		map<string, pair<int, int>> mp;
		vector<bool> same(2);
		int zero = 0;
		int one = 0;
		for (int i = 1; i <= n; ++i) {
			string s;
			cin >> s;

			if (s[0] == s.back()) {
				same[s[0] - '0'] = true;
			} else if (s[0] == '0') {
				mp[s].first = i;
				++zero;
			} else {
				reverse(s.begin(), s.end());
				mp[s].second = i;
				++one;
			}
		}

		if (same[0] && same[1] && mp.empty()) {
			cout << -1 << "\n";
			continue;
		}

		vector<int> ans;
		for (auto& [s, i] : mp) {
			if (i.first && !i.second && one + 1 < zero) {
				ans.push_back(i.first);
				--zero;
				++one;
			} else if (i.second && !i.first && zero + 1 < one) {
				ans.push_back(i.second);
				--one;
				++zero;
			}
		}

		cout << ans.size() << "\n";
		for (auto& i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
}