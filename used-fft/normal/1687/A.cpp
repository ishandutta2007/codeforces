#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, k; cin >> n >> k;


		int a[n]; for(int &i : a) cin >> i;
		int x {};

		for(int i = 0; i < n; ++i) {
			if(i) a[i] += a[i-1];
			x = max(x, a[i] - (i-k < 0 ? 0 : a[i-k]));
		}

		if(n < 2) {
			x += k - 1;
		} else {
			if(k > n) {
				x += n * (k - 1);
				// cout << x<< '\n';
				x -= (n * (n-1)) / 2LL;
			} else 
				x += (k * (k - 1)) / 2LL;
		}

		cout << x << '\n';
	}
}