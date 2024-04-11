#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n;
	ll k;
	string s;
	cin >> n >> k >> s;

	int one = 0, zer = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (one <= k) {
				++zer;
				k -= one;
			} else {
				cout << string(zer, '0');
				cout << string(one - k, '1');
				cout << '0';
				cout << string(k, '1');
				cout << s.substr(i + 1);
				cout << '\n';
				return;
			}
		} else {
			++one;
		}
	}

	cout << string(zer, '0') << string(one, '1') << '\n';
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