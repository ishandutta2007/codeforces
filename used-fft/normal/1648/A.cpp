#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9+1;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;

	map<int, vector<int>> a;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			int v; cin >> v;
			a[v].push_back(i);
			a[v+INF].push_back(j);
		}
	}

	int res = 0;

	for(auto &[_, c] : a) {
		sort(begin(c), end(c));
		int cur = 0;
		int sz = size(c);

		for(int i = 0; i < sz; ++i) {
			res += c[i] * i - cur;
			cur += c[i];
		}
		// cur = 0;
		// for(int i = sz; i--; ) {
		// 	res += c[i] * ()
		// }
	}
	cout << res;
}