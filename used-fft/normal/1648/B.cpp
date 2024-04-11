#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;

	while(T--) {
		int n, c; cin >> n >> c;

		int a[c+1];
		fill(a, a+c+1, 0);
		bool ok = 1;
		while(n--) {
			int v; cin >> v;
			++a[v];
		}

		for(int i = 1; i <= c; ++i)
			a[i] += a[i-1];

		for(int i = 1; i <= c; ++i) {
			if(!(a[i] - a[i-1])) continue;
			for(int j = 1; i * j <= c; ++j) {
				if((a[min(c, i * (j+1) - 1)] - a[i * j - 1])) {
					if(!(a[j] - a[j-1])) ok = 0;
				}
			}
		}

		cout << (ok ? "Yes" : "No") << '\n';
	}
}