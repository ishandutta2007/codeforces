#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int ab, db, nb, ac, dc, nc;
		cin >> ab >> db >> nb;
		cin >> ac >> dc >> nc;
		ab -= ac;
		ac -= ac;

		int ans {};

		int rb = ab + (nb - 1LL) * db, rc = ac + (nc - 1LL) * dc;

		if(dc % db || ab % db || ab > ac || rb < rc) {
			cout << 0 << '\n';
			continue;
		}

		vector<int> divi;
		for(int i = 1; i * i <= dc; ++i) if(!(dc % i)) {
			divi.push_back(i);
			if(i*i != dc) divi.push_back(dc / i);
		}
		for(int da : divi) if((da * db) / gcd(da, db) == dc) {
			if(-dc < ab || rc + dc > rb) {
				ans = -1;
				break;
			}
			ans += (dc / da) * (dc / da);
			ans %= MOD;
		}

		cout << ans << '\n';
	}
}