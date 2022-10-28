#include <bits/stdc++.h>
using namespace std;

string s;

int solve(int l, int r, char c) {
	if (l + 1 == r) {
		return s[l] != c;
	}

	int m = (l + r) / 2;

	int cnt_l = 0;
	int cnt_r = 0;
	for (int i = l; i < r; ++i) {
		if (i < m) {
			cnt_l += (s[i] != c);
		} else {
			cnt_r += (s[i] != c);
		}
	}

	return min(cnt_l + solve(m, r, c + 1), cnt_r + solve(l, m, c + 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n >> s;
		cout << solve(0, n, 'a') << "\n";
	}
}