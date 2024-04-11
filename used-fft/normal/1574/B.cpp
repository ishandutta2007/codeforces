#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--){
		int a, b, c, m;
		cin >> a >> b >> c >> m;

		bool ok = (a - 1 + b - 1 + c - 1) >= m;

		int req = a + b + c - m;

		int lim = (req + 1LL) / 2LL;

		m -= max(a - lim, 0LL);
		m -= max(b - lim, 0LL);
		m -= max(c - lim, 0LL);

		cout << (m >= 0 && ok ? "YES" : "NO") << '\n';
	}
}