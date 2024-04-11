#include <bits/stdc++.h> 
using namespace std;

const int MX = 15;
const int INF = 1e9;

int dp[1 << MX][MX + 1][MX + 1], fir[1 << MX][MX + 1], sum[1 << MX], a[MX];
pair<int, int> pre[1 << MX][MX + 1][MX + 1]; 

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	for (int ma = 1; ma < (1 << n); ++ma) {
		sum[ma] = 0;
		fir[ma][n] = INF;
		for (int i = n - 1; i >= 0; --i) {
			if (ma & (1 << i)) {
				fir[ma][i] = i;
				sum[ma] += a[i];
			} else {
				fir[ma][i] = fir[ma][i + 1];
			}
		}
	}

	for (int ma = 0; ma < (1 << n); ++ma) {
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				dp[ma][i][j] = INF;
			}
		}
	}
	dp[0][0][0] = 0;

	for (int ma = 0; ma < (1 << n); ++ma) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dp[ma][i][j] == INF)
					continue;
				int rma = ((1 << n) - 1) ^ ma;
				for (int nma = rma; nma; nma = (nma - 1) & rma) {
					if (sum[nma] > dp[ma][i][j] && fir[nma][j] < n) {
						if (sum[nma] < dp[ma ^ nma][i + 1][fir[nma][j] + 1]) {
							dp[ma ^ nma][i + 1][fir[nma][j] + 1] = sum[nma];
							pre[ma ^ nma][i + 1][fir[nma][j] + 1] = {nma, j};
						}
					}
				}
			}
		}
	}

	bool ok = false;
	vector<pair<int, int>> ans;
	for (int i = n; i && !ok; --i) {
		for (int j = 0; j <= n && !ok; ++j) {
			int ma = (1 << n) - 1;
			if (dp[ma][i][j] != INF) {
				while (i) {
					auto [nma, pos] = pre[ma][i][j];
					for (int k = 0; k < n; ++k) {
						if (k != j - 1 && (nma & (1 << k))) {
							ans.emplace_back(k, j - 1);
						}
					}
					ma ^= nma;
					j = pos;
					--i;
				}
				ok = true;
			}
		}
	}

	auto getndx = [&](int i) {
		int res = 1;
		for (int j = 0; j < i; ++j) {
			res += !!a[j];
		}
		return res;
	};

	cout << ans.size() << '\n';
	while (!ans.empty()) {
		auto [i, j] = ans.back();
		ans.pop_back();
		cout << getndx(i) << ' ' << getndx(j) << '\n';
		a[i] = 0;
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