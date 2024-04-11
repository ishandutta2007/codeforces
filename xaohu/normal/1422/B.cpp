#include <bits/stdc++.h>
#define pb push_back
#define sz(x)(int)x.size()
 
using ll = long long;
using namespace std;

const int N = 105;

int t, n, m, a;
vector <int> g[N][N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				g[i][j].clear();
				cin >> a;
				int x = min(i, n - i - 1);
				int y = min(j, m - j - 1);
				g[x][y].pb(a);
			}
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (g[i][j].empty()) continue;
				sort(g[i][j].begin(), g[i][j].end());
				int s = g[i][j][sz(g[i][j]) / 2];
				for (auto x : g[i][j])
					ans += abs(x - s);
			}
		cout << ans << endl;
	}
	return 0;
}