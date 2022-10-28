#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> m(n);
	for (auto& i : m) {
		cin >> i;
	}
	sort(m.begin(), m.end(), greater<int>());
	vector<int> c(k);
	for (auto& i : c) {
		cin >> i;
	}

	vector<vector<int>> cases(n), tests(n + 1);
	int mn = 0, cnt = 0;
	for (auto i : m) {
		if (!mn || mn >= c[i - 1]) {
			cases[cnt] = {i};
			tests[1].push_back(cnt++);
			mn = 1;
		} else {
			int cur = tests[mn].back();
			tests[mn].pop_back();
			cases[cur].push_back(i);
			tests[mn + 1].push_back(cur);
			if (tests[mn].empty()) {
				++mn;
			}
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i <= n; ++i) {
		for (auto j : tests[i]) {
			cout << cases[j].size();
			for (auto k : cases[j]) {
				cout << ' ' << k;
			}
			cout << '\n';
		}
	}
}