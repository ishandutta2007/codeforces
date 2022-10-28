#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& cyc, vector<int>& c, int k) {
	for (int j = 0; j < k; ++j) {
		int cur = j, col = c[cyc[j]];
		bool ok = true;
		do {
			ok = (c[cyc[cur]] == col);
			(cur += k) %= (int)cyc.size();
		} while (cur != j && ok);
		if (ok) return true; 
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector<int> p(n), c(n);
	for (auto& i : p) {
		cin >> i;
		--i;
	}
	for (auto& i : c) {
		cin >> i;
	}

	int ans = 1e9;
	vector<bool> vstd(n);
	vector<int> cyc;
	for (int i = 0; i < n; ++i) {
		if (vstd[i]) continue;
		cyc.clear();
		int j = i;
		do {
			vstd[j] = true;
			cyc.push_back(j);
			j = p[j];
		} while (!vstd[j]);
		int sz = (int)cyc.size();
		for (int k = 1; k * k <= sz; ++k) {
			if (sz % k) continue;
			if (check(cyc, c, k)) {
				ans = min(ans, k);
			} else if (check(cyc, c, sz / k)) {
				ans = min(ans, sz / k);
			}	
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}