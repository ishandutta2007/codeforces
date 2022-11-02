#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, z; cin >> n >> z;
		int a[n]; for(int &i : a) cin >> i;
		int ans {};
		for(int &i : a) ans = max(ans, i | z);
		cout << ans << '\n';
	}
}