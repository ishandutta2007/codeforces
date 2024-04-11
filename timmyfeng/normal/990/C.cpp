#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5 + 1;

ll pos[MX], neg[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int bal = 0, mn = 0;
		for (auto c : s) {
			bal += c == '(' ? 1 : -1;
			mn = min(mn, bal);
		}
		if (bal >= 0 && mn >= 0) {
			++pos[bal];
		} else if (bal < 0 && mn >= bal) {
			++neg[-bal];
		}
	}

	ll ans = pos[0] * pos[0];
	for (int i = 1; i < MX; ++i) {
		ans += pos[i] * neg[i];
	}
	cout << ans << '\n';
}