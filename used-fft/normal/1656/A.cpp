#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i;
		cout << (min_element(a, a + n) - a) + 1 << ' ' << (max_element(a, a + n) - a) + 1 << '\n';
	}
}