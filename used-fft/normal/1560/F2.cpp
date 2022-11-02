#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

#define curr(I) (mask & (1<<I))

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		int n, k; cin >> n >> k;

		string s = to_string(n);
		int sz = size(s);

		int ans = 1e18;
		for(int mask=0; mask<(1<<10); ++mask){
			if(__builtin_popcount(mask) > k) continue;
			int lowest = 10;
			for(int j=10; --j>=0; )
				if(curr(j)) lowest = j;

			int res = 0;
			for(int i=0; i<sz; ++i){
				int d = s[i] - '0';

				int use = -1;
				for(int j=10; --j>d; )
					if(curr(j))	use = j;
				if(use > 0){
					int z = res * 10 + use;
					for(int j=i+1; j<sz; ++j)
						z = z * 10 + lowest;
					ans = min(ans, z);
				}

				if(curr(d)) res = res * 10 + d;
				else res = i = 1e18;
			}
			ans = min(ans, res);
		}
		cout << ans nl;
	}
}