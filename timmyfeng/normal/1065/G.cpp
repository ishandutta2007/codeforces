#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 200 + 1;
const ll INF = 2e18;

int to[MX][3], nxt[MX][MX];
ll cnt[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	ll k;
	cin >> n >> k >> m;

	string ans = "";
	for (int i = 1; i <= m; ++i) {
		for (int c = 0; c < 3; ++c) {
			int lk = to[i - 1][c];
			to[i - 1][c] = i;
			for (int j = 0; j < 3; ++j) {
				to[i][j] = to[lk][j];
			}

			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= i; ++k) {
					if (!j) {
						nxt[j][k] = to[k][1];
						cnt[j][k] = (nxt[j][k] == i);
					} else if (j == 1) {
						nxt[j][k] = to[k][2];
						cnt[j][k] = (nxt[j][k] == i);
					} else {
						nxt[j][k] = nxt[j - 1][nxt[j - 2][k]];
						cnt[j][k] = cnt[j - 1][nxt[j - 2][k]] + cnt[j - 2][k];
						if (cnt[j][k] > INF) {
							cnt[j][k] = INF;
						}
					}
				}
			}

			ll res = cnt[n][0] + (to[nxt[n][0]][0] == i);
			if (res > k) {
				ans += "$01"[c];
				break;
			}

			to[i - 1][c] = lk;
			k -= res;
		}

		if (ans.back() == '$') {
			ans.pop_back();
			cout << ans << '\n';
			return 0;
		}
	}
	cout << ans << '\n';
}