#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		int a[n][m];
		vector<array<int, 2>> s;

		for(int i = 0; i < n; ++i) {
			for(int &j : a[i]) cin >> j;

			int f = -1;
			for(int j = 1; j < m; ++j) if(a[i][j-1] > a[i][j]) {
				f = j;
				break;
			}

			if(f < 0 || !empty(s)) continue;

			int x = f-1;
			while(x && a[i][x] == a[i][x-1]) --x;
			s.push_back({x, f});
			s.push_back({f-1, f});

			for(int j = f; j < m; ++j)
				if(a[i][j] <= a[i][f]) x = j;
			s.push_back({f-1, x});
		}

		if(empty(s)) {
			cout << "1 1\n";
		} else {
			bool done = 0;
			for(auto &[x, y] : s) {
				bool ok = 1;
				for(int i = 0; i < n; ++i) {
					swap(a[i][x], a[i][y]);
					for(int j = 1; j < m; ++j) if(a[i][j-1] > a[i][j]) ok = 0;
					swap(a[i][x], a[i][y]);
				}
				if(ok) {
					cout << x+1 << ' ' << y+1 << '\n';
					done = 1;
					break;
				}
			}
			if(!done) cout << "-1\n";
		}
	}
}