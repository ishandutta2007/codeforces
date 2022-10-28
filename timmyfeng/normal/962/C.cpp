#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int n = s.size(), ans = 20;
	for (int i = 1; i < (1 << n); ++i) {
		int res = 0;
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				if (!res && s[j] == '0') {
					ok = false;
				}
				res *= 10;
				res += s[j] - '0';
			}
		}
		if (!ok)
			continue;
		int lb = 0, rb = sqrt(INT_MAX);
		while (lb < rb) {
			int mb = (lb + rb) / 2;
			if (mb * mb < res) {
				lb = mb + 1;
			} else {
				rb = mb;
			}
		}
		if (lb * lb == res) {
			ans = min(ans, n - __builtin_popcount(i));
		}
	}
	cout << (ans == 20 ? -1 : ans) << '\n';
}