#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
vector<int> g[N], v[N], diag1[N], diag2[N];
int x[N], y[N];
signed main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		g[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
		if (x[i] >= y[i]) {
			diag1[x[i] - y[i]].pb(y[i]);
		}
		else {
			diag2[y[i] - x[i]].pb(x[i]);
		}
	}
	for (int i = 0; i <= 1e5; i++) {
		sort(all(g[i]));
		sort(all(v[i]));
		sort(all(diag1[i]));
		sort(all(diag2[i]));
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] >= y[i]) {
			int sz1 = g[x[i]].end() - upper_bound(all(g[x[i]]), y[i]), 
			sz2 = v[y[i]].end() - upper_bound(all(v[y[i]]), x[i]),
			sz3 = diag1[x[i] - y[i]].end() - upper_bound(all(diag1[x[i] - y[i]]), y[i]);
			if (sz1 < sz2 && sz1 < sz3) {
				int pos = upper_bound(all(g[x[i]]), y[i]) - g[x[i]].begin();
				for (int j = pos; j < SZ(g[x[i]]); j++) {
					int len = g[x[i]][j] - y[i];
					if (find(all(v[y[i]]), x[i] + len) != v[y[i]].end() && find(all(diag1[x[i] - y[i]]), y[i] + len) != diag1[x[i] - y[i]].end()) {
						ans++;
					}
				} 
			}
			else if (sz2 < sz3) {
				int pos = upper_bound(all(v[y[i]]), x[i]) - v[y[i]].begin();
				for (int j = pos; j < SZ(v[y[i]]); j++) {
					int len = v[y[i]][j] - x[i];
					if (find(all(g[x[i]]), y[i] + len) != g[x[i]].end() && find(all(diag1[x[i] - y[i]]), y[i] + len) != diag1[x[i] - y[i]].end()) {
						ans++;
					}
				}	
			}
			else {
				int pos = upper_bound(all(diag1[x[i] - y[i]]), y[i]) - diag1[x[i] - y[i]].begin();
				for (int j = pos; j < SZ(diag1[x[i] - y[i]]); j++) {
					int len = diag1[x[i] - y[i]][j] - y[i];
					if (find(all(v[y[i]]), x[i] + len) != v[y[i]].end() && find(all(g[x[i]]), y[i] + len) != g[x[i]].end()) {
						ans++;
					}
				}
			}			
		}
		else {
			int sz1 = g[x[i]].end() - upper_bound(all(g[x[i]]), y[i]), 
			sz2 = v[y[i]].end() - upper_bound(all(v[y[i]]), x[i]),
			sz3 = diag2[y[i] - x[i]].end() - upper_bound(all(diag2[y[i] - x[i]]), x[i]);
			if (sz1 < sz2 && sz1 < sz3) {
				int pos = upper_bound(all(g[x[i]]), y[i]) - g[x[i]].begin();
				for (int j = pos; j < SZ(g[x[i]]); j++) {
					int len = g[x[i]][j] - y[i];
					if (find(all(v[y[i]]), x[i] + len) != v[y[i]].end() && find(all(diag2[y[i] - x[i]]), x[i] + len) != diag2[y[i] - x[i]].end()) {
						ans++;
					}
				} 
			}
			else if (sz2 < sz3) {
				int pos = upper_bound(all(v[y[i]]), x[i]) - v[y[i]].begin();
				for (int j = pos; j < SZ(v[y[i]]); j++) {
					int len = v[y[i]][j] - x[i];
					if (find(all(g[x[i]]), y[i] + len) != g[x[i]].end() && find(all(diag2[y[i] - x[i]]), x[i] + len) != diag2[y[i] - x[i]].end()) {
						ans++;
					}
				}	
			}
			else {
				int pos = upper_bound(all(diag2[y[i] - x[i]]), x[i]) - diag2[y[i] - x[i]].begin();
				for (int j = pos; j < SZ(diag2[y[i] - x[i]]); j++) {
					int len = diag2[y[i] - x[i]][j] - x[i];
					if (find(all(v[y[i]]), x[i] + len) != v[y[i]].end() && find(all(g[x[i]]), y[i] + len) != g[x[i]].end()) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << '\n';
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}