#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, m, x, y; cin >> n >> m >> x >> y;
		array<int, 2> pts[4] = {{1, 1}, {1, m}, {n, 1}, {n, m}};
		vector<array<int, 2>> ans;
		int best = -1;
		for(int i=0; i<16; ++i){
			if(__builtin_popcount(i) != 2) continue;
			vector<array<int, 2>> curr;
			for(int j=0; j<4; ++j){
				if(i & (1<<j)) curr.push_back(pts[j]);
			}	
			int res = 0;
			curr.push_back({x, y});
			for(int j=1; j<3; ++j){
				res += abs(curr[j][0] - curr[j-1][0]) + abs(curr[j][1] - curr[j-1][1]);
			}
			int res1 = 0;
			swap(curr[0], curr[1]);
			for(int j=1; j<3; ++j){
				res1 += abs(curr[j][0] - curr[j-1][0]) + abs(curr[j][1] - curr[j-1][1]);
			}
			res = min(res, res1);
			if(res > best){
				curr.pop_back();
				ans = curr;
				best = res;
			}
		}
		cout << ans[0][0] sp ans[0][1] sp ans[1][0] sp ans[1][1] nl;
	}
}