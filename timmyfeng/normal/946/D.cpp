#include <bits/stdc++.h>
using namespace std;

const int MX = 500 + 1;

vector<int> sched[MX];
int dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;

		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') {
				sched[i].push_back(j);
			}
		}
	}

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;

	for (int i = 1; i <= n; ++i) {
		int sz = sched[i].size();
		for (int j = 0; j <= sz; ++j) {
			int res = m;
			if (j) {
				for (int l = 0; l + j - 1 < sz; ++l) {
					res = min(res, sched[i][l + j - 1] - sched[i][l] + 1);
				}
			} else {
				res = 0;
			}

			for (int l = 0; l + sz - j <= k; ++l) {
				dp[i][l + sz - j] = min(dp[i][l + sz - j], dp[i - 1][l] + res);
			}
		}
	}

	cout << *min_element(dp[n], dp[n] + k + 1) << '\n';
}