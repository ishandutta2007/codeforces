#include <bits/stdc++.h>
using namespace std;
#define int long long

#define remin(Y) res = min(res, Y)

const int INF = 1e18;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--){
		int n, k; cin >> n >> k;
		int a[n]; for(int &i : a) cin >> i;

		sort(a, a+n);
		reverse(a+1, a+n);

		int res = INF, sum = accumulate(a+1, a+n, 0LL);

		remin(max(0LL, sum + a[0] - k));

		for(int m=1; m<n; ++m){
			sum -= a[m];


			int req = a[0] - (k - sum) / (m + 1LL);

			while((a[0] - req) * (m + 1LL) + sum > k) ++req;
			while((a[0] - req + 1) * (m + 1LL) + sum <= k) --req;

			remin(max(0LL, req) + m);
		}

		cout << res << '\n';
	}
}