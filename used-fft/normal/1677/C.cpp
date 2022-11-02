#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i, --i;
		int b[n]; for(int &i : b) cin >> i, --i;

		int pos[n];
		for(int i = 0; i < n; ++i)
			pos[a[i]] = i;

		int ans {};
		int oh {};

		bool vis[n] {};
		for(int i = 0; i < n; ++i) if(!vis[i]) {
			int u = i, cnt {};
			for(; !vis[u]; ++cnt) {
				vis[u] = 1;
				u = pos[b[u]];
			}

			if(cnt < 2) continue;
			oh += cnt / 2;
		}
		for(int i = 1; i <= oh; ++i) {
			ans -= 2 * i;
			ans += 2 * (n + 1 - i);
		}
		cout << ans << '\n';
	}
}