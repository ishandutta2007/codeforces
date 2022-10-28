#include <bits/stdc++.h>
using namespace std;

string s, ans;
bool ok;
int n;

void dfs(int i, int mask, bool lessed) {
	if (i + __builtin_popcount(mask) > n)
		return;
	if (i == n) {
		ok = (lessed && !mask);
	} else {
		for (int j = 9; j >= 0 && !ok; --j) {
			if (!lessed && j > s[i] - '0')
				continue;
			ans[i] = j + '0';
			dfs(i + 1, mask ^ (1 << j), lessed || j < s[i] - '0');
		}
	}
}

void solve() {
	cin >> s;
	n = s.size();

	ans = string(n, 0);
	ok = false;
	dfs(0, 0, false);
	if (ok && ans[0] != '0') {
		cout << ans << '\n';
	} else {
		cout << string(n - 2, '9') << '\n';
	}
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