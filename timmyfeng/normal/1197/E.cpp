#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, thr = 0;
	cin >> n;
	set<int> pt;
	map<int, vector<int>> pos;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		pos[a].push_back(b);
		pt.insert(a);
		pt.insert(b);
		thr = max(thr, b);
	}

	map<int, pair<int, int>> mp;
	mp[0] = {0, 1};
	int best = 1e9, ans = 0, pb = 0, pc = 1;
	for (auto i : pt) {
		auto& [mn, cnt] = mp[i];
		mn = i - pb;
		cnt = pc;
		for (auto j : pos[i]) {
			auto [m, c] = mp[j];
			if (m < mn) {
				mn = m;
				cnt = c;
			} else if (m == mn) {
				cnt = (cnt + c) % M;
			}
		}
		if (i > thr) {
			if (mn < best) {
				best = mn;
				ans = cnt;
			} else if (mn == best) {
				ans = (ans + cnt) % M;
			}
		}
		pb = i - mn;
		pc = cnt;
	}
	cout << ans << '\n';
}