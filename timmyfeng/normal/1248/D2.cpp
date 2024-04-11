#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> bal(n);
	for (int i = 0; i < n; ++i) {
		bal[i] = (i ? bal[i - 1] : 0) + (s[i] == '(' ? 1 : -1);
	}
	if (bal[n - 1]) {
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		return 0;
	}
	int offset = min_element(bal.begin(), bal.end()) - bal.begin();
	rotate(bal.begin(), bal.begin() + offset, bal.end());
	for (int i = n - 1; ~i; --i) {
		bal[i] -= bal[0];
	}

	int zer = count(bal.begin(), bal.end(), 0);
	int ans = zer, ans1 = 1, ans2 = 1, j;
	for (int i = 0; i < n; i = j) {
		for (j = i + 1; j < n && bal[j]; ++j);
		int r, one = 0;
		for (int l = i + 1; l < j; l = r) {
			++one;
			int two = 0;
			for (r = l + 1; r < j && bal[r] > 1; ++r) {
				if (bal[r] == 2) {
					++two;
				}
			}
			if (zer + two > ans) {
				ans = zer + two;
				ans1 = l;
				ans2 = r - 1;
			}
		}
		if (one > ans) {
			ans = one;
			ans1 = i;
			ans2 = j - 1;
		}
	}
	cout << ans << '\n';
	cout << (ans1 + offset + 1) % n + 1 << ' ' << (ans2 + offset + 1) % n + 1 << '\n';
}