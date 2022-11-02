#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int p[n]; for(int &i : p) cin >> i;
		int ans = 0;

		int a[n] {};

		for(int i = 0; i < n; ++i) {
			int cnt {};
			for(int j = i + 1; j < n; ++j) {
				if(p[j] < p[i]) ans += cnt;
				cnt += a[j];
			}

			for(int j = i + 1; j < n; ++j)
				a[j] += p[j] > p[i];
		}
		cout << ans << '\n';
	}
}