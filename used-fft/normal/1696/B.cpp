#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int cnt {};


		int a[n];
		for(int &i : a) {
			cin >> i;
			cnt += !i;
		}

		if(cnt == n) {
			cout << 0 << '\n';
		} else {
			int l = 0;
			int r = 0;

			for(int i = 0; i < n; ++i) {
				if(!a[i]) ++l;
				else break;
			}
			for(int i = n; i--; ) {
				if(!a[i]) ++r;
				else break;
			}
			cout << (l + r == cnt ? 1 : 2) << '\n';
		}
	}
}