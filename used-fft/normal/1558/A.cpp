#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int a, b; cin >> a >> b;
		int sum = a + b;

		int x = (sum) / 2, y = sum - x;

		bool pos[sum+1];
		fill(pos, pos+sum+1, 0);

		for(int i=0; i<=min(a, x); ++i){
			int bLeft = b - (x - i);
			if(bLeft < 0) continue;

			int aLeft = a - i;

			pos[i + bLeft] = 1;
		}

		swap(x, y);


		for(int i=0; i<=min(a, x); ++i){
			int bLeft = b - (x - i);
			if(bLeft < 0) continue;

			// int aLeft = a - i;

			pos[i + bLeft] = 1;
		}

		int ans = 0;
		for(int i=0; i<=sum; ++i) ans += pos[i];
		cout << ans << '\n';
		for(int i=0; i<=sum; ++i) if(pos[i]) cout << i << ' ';
		cout << '\n';
	}
}