#include <bits/stdc++.h>
using namespace std;

const int MX = 5000;

int diff[MX];
string s[MX];

bool anagram(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; ++i) {
		cin >> s[i];
	}

	for (int i = 1; i < k; ++i) {
		if (!anagram(s[0], s[i])) {
			cout << -1 << '\n';
			return 0;
		}
		for (int j = 0; j < n; ++j) {
			diff[i] += (s[0][j] != s[i][j]);
		}
	}

	bool same = false;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[0][i] == s[0][j]) {
				same = true;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			bool ok = true;
			for (int l = 1; l < k; ++l) {
				int new_diff = diff[l] -
						(s[0][i] != s[l][i]) -
						(s[0][j] != s[l][j]) +
						(s[0][i] != s[l][j]) +
						(s[0][j] != s[l][i]);
				ok &= (new_diff == 2 || (!new_diff && same));
			}
			if (ok) {
				swap(s[0][i], s[0][j]);
				cout << s[0] << '\n';
				return 0;
			}
		}
	}
	cout << -1 << '\n';
}