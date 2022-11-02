#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		if(n < 2) cout << "-1\n";
		else {
			for(int i {}; i += 2; ) {
				if((i + 2 * (n - 2)) % 3) {
					for(int j = 2; j < n; ++j) cout << 2;
					cout << i;
					cout << "3\n";
					break;
				}
			}
		}
	}
}