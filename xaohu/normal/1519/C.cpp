#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int n, u[200111];
vector<long long> g[200111];
long long ans[200111], pref[200111];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) g[i].clear(), ans[i] = 0;
		rep(i, 1, n) cin >> u[i];
		rep(i, 1, n) {
			int p; cin >> p;
			g[u[i]].push_back(p);
		}
		rep(i, 1, n) { 
			sort(g[i].begin(), g[i].end());
			rep(j, 0, (int)g[i].size() - 1)
				pref[j + 1] = pref[j] + g[i][j];
			rep(j, 1, (int)g[i].size())
				ans[j] += pref[(int)g[i].size()] - pref[(int)g[i].size() % j];
		}
		rep(i, 1, n)
			cout << ans[i] << " "; 
		cout << "\n";
	}
	
	return 0;
}