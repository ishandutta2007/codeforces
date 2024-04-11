#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i;

		int res = 0;

		for(int z=50; --z>=0; ){
			int x = res + (1LL<<z);

			int b[n];
			bool ok = 1;
			for(int i=0; i<n; ++i) b[i] = a[i];

			for(int i=n; --i>=2; ){
				if(b[i] < x) ok = 0;
				int rem = min(a[i], b[i] - x);
				rem /= 3LL;

				b[i-1] += rem;
				b[i-2] += rem * 2LL;
			}

			ok = ok && b[0] >= x && b[1] >= x;
			if(ok) res |= x;
		}

		cout << res << '\n';
	}
}