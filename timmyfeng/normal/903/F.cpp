#include <bits/stdc++.h> 
using namespace std;

const int MX = 1000 + 5;
const int INF = 0x3f3f3f3f;

int a[4], dp[MX * 4][1 << 12];
string s[4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < 4; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> s[i];
	}

	int init = 0;
	for (int i = 0; i < 12; ++i) {
		init ^= (s[i % 4][i / 4] == '.') << i;
	}
	memset(dp, INF, sizeof dp);
	dp[0][init] = 0;

	for (int i = 0; i < n * 4; ++i) {
		for (int mask = 0; mask < (1 << 12); ++mask) {
			if (dp[i][mask] == INF)
				continue;

			int nxt = (s[i % 4][i / 4 + 3] == '.');
			if (mask & (1 << 0)) {
				int new_mask = (mask >> 1) | (nxt << 11);
				dp[i + 1][new_mask] = min(dp[i + 1][new_mask], dp[i][mask]);
			}

			for (int k = 1; i % 4 + k <= 4; ++k) {
				int new_mask = mask;
				for (int x = 0; x < k; ++x) {
					for (int y = 0; y < k; ++y) {
						new_mask |= 1 << (x * 4 + y);
					}
				}
				if (k < 4) {
					new_mask >>= 1;
					new_mask ^= nxt << 11;
					dp[i + 1][new_mask] = min(dp[i + 1][new_mask], dp[i][mask] + a[k - 1]);
				} else {
					new_mask >>= 4;
					dp[i + 4][new_mask] = min(dp[i + 4][new_mask], dp[i][mask] + a[k - 1]);
				}
			}
		}
	}
	cout << *min_element(dp[4 * n], dp[4 * n] + (1 << 12)) << '\n';
}