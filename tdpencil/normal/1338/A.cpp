#include <bits/stdc++.h>
using namespace std;

typedef long long ull;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while(t-- ){
		int n; cin >> n;
		vector<ull> a(n);
		auto findd=[&](ull x) -> ull{
			if(x <= 0) return 0;
			int cnt = 0;
			ull p = 0;
			for(int i = 32; i >= 0; i--) {
				if(p + (1LL << i) <= x) {
					p += (1LL << i);
					cnt = max(i + 1, cnt);
				}
			}
			
			return cnt;
		};
		
		for(ull &i : a) {
			cin >> i;
		}
		
		if(is_sorted(a.begin(), a.end())) {
			cout << 0 << "\n";
			continue;
		}
		
		ull mx = -2e9;
		ull ans = 0;
		for(ull &i : a) {
//			cout << mx - i << "\n";
			ans = max(ans, findd(mx - i) == 0 ? 0 : findd(mx - i));
			mx = max(mx, i);
		}
		cout << ans << "\n";
	}
}