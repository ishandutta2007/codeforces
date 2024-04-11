#include <bits/stdc++.h>
using namespace std;

string tgt = "abacaba";

void solve() {
	int n;
	string s;
	cin >> n >> s;

	for (int i = 0; i <= n - 7; ++i) {
		string t = s;
		for (int j = 0; j < 7; ++j) {
			if (t[i + j] == '?') {
				t[i + j] = tgt[j];
			}
		}
		int cnt = 0;
		for (int j = 0; j <= n - 7; ++j) {
			if (t.substr(j, 7) == tgt) {
				++cnt;
			}
		}
		if (cnt == 1) {
			for (auto& i : t) {
				if (i == '?'){
					i = 'z';
				}
			}
			cout << "Yes\n";
			cout << t << "\n";
			return;
		}
	}
	cout << "No\n";
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