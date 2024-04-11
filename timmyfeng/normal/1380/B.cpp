#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		map<char, int> mp;
		for (auto i : s) {
			++mp[i];
		}

		if (mp['R'] > mp['S'] && mp['R'] > mp['P']) {
			cout << string(s.size(), 'P') << "\n";
		} else if (mp['P'] > mp['S']) {
			cout << string(s.size(), 'S') << "\n";
		} else {
			cout << string(s.size(), 'R') << "\n";
		}
	}
}