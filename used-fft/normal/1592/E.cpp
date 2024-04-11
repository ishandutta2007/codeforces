#include <bits/stdc++.h>
using namespace std;
#define sp << ' ' <<
#define nl << '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	int a[n+1] {};
	for(int i = 1; i <= n; ++i) cin >> a[i];

	int ans {};
	vector<vector<int>> g {vector<int> (n + 1)}, h;

	iota(begin(g[0]), end(g[0]), 0);

	for(int b = 20; b--; ) {
		
		int group[n+1] {};

		for(int i = 1; i <= n; ++i)
			group[i] = group[i-1] ^ bool(a[i] & (1<<b));

		h.clear();
		h.swap(g);

		for(auto c : h) {
			vector<int> cur[2];
			for(int i : c) cur[group[i]].push_back(i);

			for(int i : {0, 1}) if(!empty(cur[i]))
				g.push_back(cur[i]);
		}

		int l[n + 1], last {};

		for(int i = 0; i <= n; ++i) {
			if(!(a[i] & (1<<b))) last = i;
			l[i] = last;
		}

		for(auto c : g) {
			int p {};
			for(int j = 0; j < (int)(size(c)); ++j) {
				for(; c[p] < l[c[j]]; ++p);

				ans = max(ans, c[j] - c[p]);
			}
		}
	}

	cout << ans;
}