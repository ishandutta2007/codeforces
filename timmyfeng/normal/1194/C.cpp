#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s, t, p;
	cin >> s >> t >> p;
	int n = s.size();
	int m = t.size();
	vector<int> freq(26);
	bool ok = false;
	for (int i = 0, j = 0; i < m; ++i) {
		if (j < n && s[j] == t[i]) {
			if (++j == n) {
				ok = true;
			}
		} else {
			++freq[t[i] - 'a'];
		}
	}
	for (auto i : p) {
		--freq[i - 'a'];
	}
	ok &= *max_element(freq.begin(), freq.end()) <= 0;
	cout << (ok ? "YES" : "NO") << '\n';
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