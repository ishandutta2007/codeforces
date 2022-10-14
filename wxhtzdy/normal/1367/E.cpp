#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;

	while (test--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> cnt(26);

		for (char c : s) {
			cnt[c - 'a']++;
		}

		for (int len = n; len >= 1; len--) {
			vector<bool> used(len);
			vector<int> cycles;

			for (int i = 0; i < len; i++) {
				if (used[i]) {
					continue;
				}

				int j = (i + k) % len;
				used[i] = true;
				cycles.push_back(0);
				cycles.back()++;

				while (!used[j]) {
					cycles.back()++;
					used[j] = true;
					j = (j + k) % len;
				}
			}

			vector<int> cur_cnt(cnt);

			sort(cycles.begin(), cycles.end());
			sort(cur_cnt.begin(), cur_cnt.end());

			bool can_fill = true;

			while (!cycles.empty()) {
				if (cur_cnt.back() < cycles.back()) {
					can_fill = false;
					break;
				} else {
					cur_cnt.back() -= cycles.back();
					cycles.pop_back();
					sort(cur_cnt.begin(), cur_cnt.end());
				}
			}

			if (can_fill) {
				cout << len << endl;
				break;
			}
		}
	}
}