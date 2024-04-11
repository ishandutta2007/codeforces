#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<int>> pos(n + 1);
		for (int p = 0; p < n; p++) {
			int x;
			cin >> x;
			pos[x].push_back(p);
		}
		vector<int> ans;
		int cur_pos = 0;
		while (cur_pos < n) {
			int i = 0;
			int next_pos = cur_pos + 1;
			while (i <= n) {
				auto it = lower_bound(pos[i].begin(), pos[i].end(), cur_pos);
				if (it == pos[i].end()) break;
				next_pos = max(next_pos, 1 + *it);
				++i;
			}
			ans.push_back(i);
			cur_pos = next_pos;
		}
		cout << ans.size() << "\n";
		for (int &x : ans) cout << x << " ";
		cout << "\n";
	}
}