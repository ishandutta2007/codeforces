#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[n], b[n];
		for(int &i : a) cin >> i, --i;
		for(int &i : b) cin >> i, --i;

		int f[n] {}, need[n] {}, c[n] {1};
		for(int &i : a) ++f[i];

		for(int i = 1; i < n; ++i)
			c[i] = 1 + (b[i] == b[i-1] ? c[i-1] : 0);
		bool ok = 1;

		for(int i = n, j = n - 1; i--; ) {
			if(j >= 0 && a[i] == b[j]) {
				need[a[i]] += c[j] - 1;
				j -= c[j];
			} else {
				ok = ok && need[a[i]];
				--need[a[i]];
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}