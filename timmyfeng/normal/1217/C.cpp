#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			++ans;
			ans += (s[i + 1] == '0');
		}
	}

	int ct = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			++ct;
		} else {
			int cur = 0, j = i;
			while (j < n) {
				cur *= 2;
				cur += s[j++] == '1';
				++ct;
				if (cur > ct) break;
				if (cur > 2) {
					++ans;
				}
			}
			ct = 0;
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