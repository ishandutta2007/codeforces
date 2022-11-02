#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int LIM = 2e5+10;
 
int cnt[LIM][20];
 
signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
 
	for(int i=1; i<LIM; ++i){
		for(int j=0; j<20; ++j){
			cnt[i][j] = cnt[i-1][j];
			if(i & (1<<j)) cnt[i][j]++;
		}
	}
 
	int T; cin >> T;
	while(T--){
		int l, r;
		cin >> l >> r;
 
		int res = r - l;
 
		for(int j=0; j<20; ++j){
			res = min(res, r - l + 1 - (cnt[r][j] - cnt[l-1][j]));
		}
 
		cout << res << '\n';
	}
}