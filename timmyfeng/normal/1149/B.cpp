#include <bits/stdc++.h>
using namespace std;

const int MX = 256;
const int AL = 26;

int dp[MX][MX][MX];
int nxt[AL][100001];
string s[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	string t;
	cin >> n >> q >> t;

	for (int i = n; i >= 0; --i) {
		for (int j = 0; j < AL; ++j) {
			if (i >= n) {
				nxt[j][i] = n;
			} else if (t[i] == j + 'a') {
				nxt[j][i] = i;
			} else {
				nxt[j][i] = nxt[j][i + 1];
			}
		}
	}

	for (int i = 0; i < MX; ++i) {
		for (int j = 0; j < MX; ++j) {
			for (int k = 0; k < MX; ++k) {
				dp[i][j][k] = n;
			}
		}
	}

	dp[0][0][0] = -1;
	while (q--) {
		int a;
		char type;
		cin >> type >> a;
		--a;

		if (type == '+') {
			char c;
			cin >> c;
			s[a] += c;

			for (int i = a == 0 ? s[0].size() - 1u : 0; i <= int(s[0].size()); ++i) {
				for (int j = a == 1 ? s[1].size() - 1u : 0; j <= int(s[1].size()); ++j) {
					for (int k = a == 2 ? s[2].size() - 1u : 0; k <= int(s[2].size()); ++k) {
						if (dp[i][j][k] < n) {
							if (i < int(s[0].size())) {
								dp[i + 1][j][k] = min(dp[i + 1][j][k], nxt[s[0][i] - 'a'][dp[i][j][k] + 1]);
							}
							if (j < int(s[1].size())) {
								dp[i][j + 1][k] = min(dp[i][j + 1][k], nxt[s[1][j] - 'a'][dp[i][j][k] + 1]);
							}
							if (k < int(s[2].size())) {
								dp[i][j][k + 1] = min(dp[i][j][k + 1], nxt[s[2][k] - 'a'][dp[i][j][k] + 1]);
							}
						}
					}
				}
			}
		} else {
			for (int i = a == 0 ? s[0].size() : 0; i <= int(s[0].size()); ++i) {
				for (int j = a == 1 ? s[1].size() : 0; j <= int(s[1].size()); ++j) {
					for (int k = a == 2 ? s[2].size() : 0; k <= int(s[2].size()); ++k) {
						dp[i][j][k] = n;
					}
				}
			}

			s[a].pop_back();
		}

		int res = dp[s[0].size()][s[1].size()][s[2].size()];
		cout << (res < n ? "YES" : "NO") << "\n";
	}
}