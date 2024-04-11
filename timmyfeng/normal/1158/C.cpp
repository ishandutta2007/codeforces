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
		vector<int> nxt(n);
		for (auto& i : nxt) {
			cin >> i;
			if (i != -1) {
				--i;
			}
		}

		bool ok = true;
		vector<int> stk = {n};
		vector<vector<int>> pos(n + 1);
		for (int i = 0; i < n; ++i) {
			if (nxt[i] == -1) {
				nxt[i] = i + 1;
			}
			if (i == stk.back()) {
				stk.pop_back();
			}
			if (nxt[i] < stk.back()) {
				stk.push_back(nxt[i]);
			} else if (nxt[i] > stk.back()) {
				ok = false;
			}
			pos[nxt[i]].push_back(i);
		}

		if (!ok) {
			cout << -1 << "\n";
			continue;
		}

		int cur = 0;
		vector<int> ans(n);
		for (int i = 0; i <= n; ++i) {
			while (!pos[i].empty()) {
				ans[pos[i].back()] = ++cur;
				pos[i].pop_back();
			}
		}

		for (auto& i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
}