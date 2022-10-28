#include <bits/stdc++.h>
using namespace std;

const int CODE[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
const int MX = 2e3;

int dist[1 << 7][10];
int dp[MX + 1][MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		string s;
		cin >> s;
		i = bitset<7>(s).to_ulong();
	}
	reverse(a.begin(), a.end());

	for (int i = 0; i < (1 << 7); ++i) {
		for (int j = 0; j < 10; ++j) {
			if ((i & CODE[j]) != i) {
				dist[i][j] = -1;
			} else {
				dist[i][j] = __builtin_popcount(CODE[j] ^ i);
			}
		}
	}

	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int k = 0; k < 10; ++k) {
				int prev = j - dist[a[i - 1]][k];
				if (prev < 0 || dist[a[i - 1]][k] == -1 || dp[i - 1][prev] == -1) continue;
				dp[i][j] = max(dp[i][j], k);
			}
		}
	}

	if (dp[n][k] == -1) {
		cout << -1 << '\n';
		return 0;
	}
	int j = k;
	for (int i = n; i; --i) {
		cout << dp[i][j];
		j -= dist[a[i - 1]][dp[i][j]];
	}
	cout << '\n';
}