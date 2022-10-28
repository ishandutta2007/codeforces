#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 50;
const int LOG = 20;

int par[LOG][MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		par[0][a] = max(par[0][a], b);
	}
	for (int i = 1; i <= MX; ++i) {
		par[0][i] = max({i, par[0][i], par[0][i - 1]});
	}

	for (int i = 1; i < LOG; ++i) {
		for (int j = 0; j <= MX; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		if (par[LOG - 1][a] < b) {
			cout << -1 << '\n';
			continue;
		}	
		int ans = 0;
		for (int i = LOG - 1; i >= 0; --i) {
			if (par[i][a] == a) continue;
			if (par[i][a] < b) {
				ans += 1 << i;
				a = par[i][a];
			}
		}
		cout << ans + 1 << '\n';
	}
}