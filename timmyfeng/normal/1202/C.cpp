#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, bool> solve(string s, char neg, char pos) {
	int mn = 0, mx = 0, fmn = 0, lmn = 0, fmx = 0, lmx = 0, cur = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == neg) {
			--cur;
		} else if (s[i] == pos) {
			++cur;
		}
		if (cur < mn) {
			mn = cur;
			fmn = lmn = i;
		} else if (cur == mn) {
			lmn = i;
		}
		if (cur > mx) {
			mx = cur;
			fmx = lmx = i;
		} else if (cur == mx) {
			lmx = i;
		}
	}
	return {mx - mn + 1, mx - mn > 1 && (lmx < fmn || lmn < fmx)};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		auto a = solve(s, 'S', 'W'), b = solve(s, 'A', 'D');
		if (a > b) {
			swap(a, b);
		}
		if (a.second) {
			--a.first;
		} else if (b.second) {
			--b.first;
		}
		cout << (ll)a.first * b.first << '\n';
	}
}