#include <bits/stdc++.h>
using namespace std;
#define int int64_t
 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int s = n;
		while(!(s & 1)) s >>= 1;

		if(s < 2) {
			cout << -1 << '\n';
		} else {
			

			for(int k = 2; k < n; k += k) {
				int sum = (k * (k-1)) >> 1;
				if(sum < n && (n % k == sum % k)) {
					s = k;
				}
			}
			cout << s << '\n';
		}
	}
}