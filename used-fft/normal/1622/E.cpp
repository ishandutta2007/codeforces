#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int LIM = 1e4, INF = 1e18;
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, m; cin >> n >> m;
 
		int res = -1;
		int y[m];
 
		int x[n]; for(int &i : x) cin >> i;
 
		bitset<LIM> s[n];
		for(auto &i : s) cin >> i;
 
		for(int i=0; i<(1<<n); ++i){
			int cost[m] = {}, cnt[m] = {};
 
			fill(cnt, cnt+m, INF);
 
			for(int j=0; j<n; ++j){
				int add = (i & (1<<j)) ? -1 : 1;
				for(int k=0; k<m; ++k)
					if(s[j][k]) cost[k] += add, cnt[k] = min(cnt[k], x[j]);
			}
 
			int curr = 0;
 
			int b[m]; iota(b, b+m, 0LL);
			sort(b, b+m, [&](int p, int j){
				return make_pair(cost[p], cnt[p]) < make_pair(cost[j], cnt[j]);
			});
 
			for(int k=0; k<m; ++k)
				cost[b[k]] = k+1;
 
			for(int j=0; j<n; ++j){
				int sum = 0;
				for(int k=0; k<m; ++k)
					if(s[j][k]) sum += cost[k];
				curr += abs(x[j] - sum);
			}
 
			if(curr > res){
				res = curr;
				for(int k=0; k<m; ++k)
					y[k] = cost[k];
			}
		}
 
		reverse(y, y+m);
		for(int &i : y) cout << i << ' ';
		cout << '\n';
	}
}