#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		vector<int> cnt(n+n+5);
		for(int i=0; i<n; ++i){
			int j; cin >> j;
			++cnt[j-i+n];
		}
		int ans = 0;
		for(int i=0; i<n+n+5; ++i){
			ans += (cnt[i] * (cnt[i] - 1LL)) / 2LL;
		}
		cout << ans << '\n';
	}
}