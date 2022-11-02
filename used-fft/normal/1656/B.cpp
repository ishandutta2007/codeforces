#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n, k; cin >> n >> k;

		map<int, bool> m;
		bool ok = 0;
		for(int i = 0; i < n; ++i) {
			int v; cin >> v;
			if(m[k + v]) ok = 1;
			if(m[v - k]) ok = 1;
			m[v] = 1;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}