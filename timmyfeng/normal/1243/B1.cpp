#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s, t;
		cin >> n >> s >> t;

		vector<pair<char, char>> mis;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				mis.emplace_back(s[i], t[i]);
				if (mis.size() > 2) {
					break;
				}
			}
		}
		if (mis.size() == 0 || mis.size() == 2 && mis[0].first == mis[1].first && mis[0].second == mis[1].second) {
			cout << "Yes" << '\n';
		} else {
			cout << "No\n";
		}
	}
}