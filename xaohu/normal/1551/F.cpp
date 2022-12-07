#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int P = 1000000007;
int t, n, k, cnt[111];
vector<int> e[111];

void dfs(int u, int p, int dep) {
	cnt[dep]++;
	for (auto v : e[u])
		if (v != p)
			dfs(v, u, dep + 1);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			e[i].clear();

		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			e[a].push_back(b);
			e[b].push_back(a);
		}

		if (k == 2) {
			cout << 1ll * n * (n - 1) / 2 << "\n";
			continue;
		}

		int res = 0;
		for (int d = 1; d <= n; d++) {
			for (int mid = 0; mid < n; mid++) {
				vector<int> dp(n + 1, 0);
				dp[0] = 1;

				for (auto u : e[mid]) {
					memset(cnt, 0, sizeof cnt);
					dfs(u, mid, 1);

					for (int i = n - 1; 0 <= i; i--)
						dp[i + 1] = (dp[i + 1] + 1ll * dp[i] * cnt[d]) % P;
				}
				res = (res + dp[k]) % P;
			}
		}
		cout << res << "\n";
	}
	return 0;
}