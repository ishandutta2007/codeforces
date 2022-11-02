#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, k; cin >> n >> k;
		int a[n]; for(int &i : a) cin >> i;
		array<int, 2> b[n];
		for(int i = 0; i < n; ++i) {
			b[i] = {-i-a[i], -i};
		}
		sort(b, b + n);
		bool c[n] {};
		int done {}, ans {};
		for(int i = 0; i < k; ++i) {
			c[-b[i][1]] = 1;
		}
		for(int i = 0; i < n; ++i) {
			if(c[i]) ++done;
			else ans += done + a[i];
		}
		cout << ans << '\n';
	}
}