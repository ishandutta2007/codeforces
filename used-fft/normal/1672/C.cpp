#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i;

		int cur {}, l = n, r = -1;
		for(int i = 0; i < n - 1; ++i) {
			if(a[i] == a[i+1]) {
				l = min(l, i);
				r = max(r, i);
				++cur;
			}
		}
		int oh = 2e9, ans {};

		for(int i = n - 1; i && cur > 1; --i) {
			if(a[i] == a[i+1]) {
				if(i-1) cur -= a[i-2] == a[i-1];
				cur += a[i-1] != a[i];
				--cur;
				a[i-1] = a[i] = oh++;
				++ans;
			}
		}
		cout << ans << '\n';
	}
}