#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		bool one {};
		int a[n];
		for(int &i : a) {
			cin >> i;
			if(i == 1) one = 1;
		}
		if(!one) {
			cout << "YES\n";
		} else {
			sort(a, a + n);
			bool ok = 1;
			for(int i = 0; i + 1 < n; ++i)
				if(a[i] + 1 == a[i+1]) ok = 0;
			cout << (ok ? "YES" : "NO") << '\n';
		}
	}
}