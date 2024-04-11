#include <bits/stdc++.h> 
using namespace std;

const int MX = 5000 + 1;

int dp[2][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	int m = 0;
	while ((2 << m) <= n) {
		++m;
	}

	string ans = "";
	dp[0][0] = true;
	for (int i = 0; i <= n - (1 << m); ++i) {
		int ii = i % 2;
		char cur = 'z';
		vector<int> pos;

		for (int mask = 0; mask < (1 << m); ++mask) {
			if (!dp[ii][mask])
				continue;

			for (int j = 0; j < m; ++j) {
				if (!(mask & (1 << j))) {
					dp[ii][mask ^ (1 << j)] = true;
				}
			}

			if (s[i + mask] < cur) {
				cur = s[i + mask];
				pos.clear();
			}
			if (s[i + mask] == cur) {
				pos.push_back(mask);
			}
		}

		ans += cur;

		fill(dp[ii ^ 1], dp[ii ^ 1] + (1 << m), false);
		for (auto mask : pos) {
			dp[ii ^ 1][mask] = true;
		}
	}
	cout << ans << '\n';
}