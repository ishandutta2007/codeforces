#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;

		array<int, 2> ans {-1}, mx {-INF}, mn {-INF};

		for(int i = 0; i < n; ++i) {
			int v; cin >> v;
			if(mx[0] - v > i)
				ans = {mx[1], i};
			if(mn[0] + v > i)
				ans = {mn[1], i};
			mx = max(mx, {i + v, i});
			mn = max(mn, {i - v, i});
		}

		if(ans[0] < 0)
			cout << "NO\n";
		else {
			cout << "YES\n";
			cout << ans[0]+1 << ' ' << ans[1]+1 << '\n';
		}
	}
}