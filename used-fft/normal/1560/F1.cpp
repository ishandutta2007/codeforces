#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	
	vector<int> on[11];

	for(int i=0; i<(1<<10); ++i)
		on[__builtin_popcount(i)].push_back(i);

	int T; cin >> T;
	while(T--){
		int n, k; cin >> n >> k;

		string s = to_string(n);
		int sz = size(s);

		int ans = 1e18;
		for(int _=1; _<=k; ++_){
			for(int mask : on[_]){
				bool curr[10] = {};
				for(int i=0; i<10; ++i)
					if(mask & (1<<i)) curr[i] = 1;

				int lowest = 10;
				for(int j=0; j<10; ++j){
					if(curr[j]){
						lowest = j;
						break;
					}
				}

				int res = 0;
				for(int i=0; i<sz; ++i){
					int d = s[i] - '0';

					int use = -1;
					for(int j=d+1; j<10; ++j)
						if(curr[j]) use = j;
					if(use >= 0){
						int z = res;
						z = z * 10 + use;
						for(int j=i+1; j<sz; ++j){
							z = z * 10 + lowest;
						}
						ans = min(ans, z);
					}

					if(curr[d]) res = res * 10 + d;
					else{
						use = -1;
						for(int j=d; j<10; ++j){
							if(curr[j]){
								use = j;
								break;
							}
						}
						if(use < 0){
							res = -1;
							break;
						}
						res = res * 10 + use;
						for(int j=i+1; j<sz; ++j){
							res = res * 10 + lowest;
						}
						break;
					}
				}
				if(res >= 0){
					assert(res >= n);
					ans = min(ans, res);
				}
			}
		}
		cout << ans nl;
	}
}