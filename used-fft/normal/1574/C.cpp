#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int n; cin >> n;
	int a[n]; for(int &i : a) cin >> i;
	sort(a, a+n);

	int sum = accumulate(a, a+n, 0LL);

	int m; cin >> m;

	while(m--){
		int x, y; cin >> x >> y;

		int j = lower_bound(a, a+n, x) - a;

		int res = 9e18;

		if(j){
			int i = j - 1;
			res = min(res, x - a[i] + max(0LL, y - (sum - a[i])));
		}

		if(j < n) res = min(res, max(0LL, y - (sum - a[j])));

		cout << res << '\n';
	}
}