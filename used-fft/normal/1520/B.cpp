#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		bool ok = true;
		int ans = 0;
		for(int dig=1; dig<20 && ok; ++dig){
			for(int i=1; i<10 && ok; ++i){
				int res = 0;
				for(int j=0; j<dig; ++j) res = res * 10LL + i;
				if(res <= n) ++ans;
				else ok = false;
			}
		}
		cout << ans << '\n';
	}

}