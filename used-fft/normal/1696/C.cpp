#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		vector<array<int, 2>> a, b;

		for(int i = 0; i < n; ++i) {
			int v, p {}; cin >> v;
			int x = v;
			while(!(v % m)) {
				++p;
				v /= m;
			}
			p = x / v;

			if(a.empty() || a.back()[0] != v)
				a.push_back({v, p});
			else
				a.back()[1] += p;
		}
		int k; cin >> k;

		for(int i = 0; i < k; ++i) {
			int v, p {}; cin >> v;
			int x = v;
			while(!(v % m)) {
				++p;
				v /= m;
			}
			p = x / v;

			if(b.empty() || b.back()[0] != v)
				b.push_back({v, p});
			else
				b.back()[1] += p;
		}


		bool ok = 1;
		if(a.size() != b.size()) {
			cout << "No\n";
			continue;
		}

		n = a.size();
		for(int i = 0; i < n; ++i) {
			if(a[i][0] != b[i][0]) ok = 0;
			if(a[i][1] != b[i][1]) ok = 0;
		}

		cout << (ok ? "Yes" : "No") << '\n';


	}
}