#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 14;

vector<vector<ll>> dp[MX][MX];
vector<int> comb[MX];
int ndx[1 << MX];
string adj[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> adj[i];
	}

	for (int i = 1; i < (1 << n); ++i) {
		int cnt = __builtin_popcount(i) - 1;
		ndx[i] = comb[cnt].size();
		comb[cnt].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j].assign(comb[i].size(), vector<ll>(1 << i));
		}
	}

	for (int i = 0; i < n; ++i) {
		dp[0][i][i][0] = 1;
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < (int)comb[i].size(); ++k) {
				for (int ma = 0; ma < (1 << i); ++ma) {
					if (!dp[i][j][k][ma])
						continue;
					for (int nj = 0; nj < n; ++nj) {
						if (comb[i][k] & (1 << nj))
							continue;
						int nk = ndx[comb[i][k] ^ (1 << nj)];
						int nma = (ma << 1) | (adj[j][nj] & 1);
						dp[i + 1][nj][nk][nma] += dp[i][j][k][ma];
					}
				}
			}
		}
	}

	for (int ma = 0; ma < (1 << (n - 1)); ++ma) {
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += dp[n - 1][i][0][ma];
		}
		cout << ans << ' ';
	}
	cout << '\n';
}