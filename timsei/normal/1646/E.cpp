#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int n, m, ans;
bool vis[N], B[N * 20];

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		if(vis[i]) continue;
		if(i == 1) {
			++ ans;
			continue;
		}
		int now = 1, it = i;
		while(it * i <= n) {
			it = it * i; vis[it] = 1; ++ now;
		}
//		cerr << i <<' ' << ans << endl;
		
		if(i <= 11) {
			memset(B, 0, sizeof(B));
			for(int i = 1; i <= now; ++ i) {
				for(int j = i; j <= i * m; j += i)
				B[j] = 1;
			}
			for(int i = 1; i <= now * m; ++ i) ans += B[i];
			continue;
		}
		for(int i = 1; i <= now; ++ i) {
			for(int j = 0; j < (1 << (now - i + 1)); ++ j) {
				int bc = 0, who = 1;
				for(int k = i; k <= now; ++ k) {
					if((j >> (k - i)) & 1) {
						++ bc; who = who * k / __gcd(who, k);
					}
				}
				if(bc == 0) continue;
				if(bc & 1) ans += (m * i) / who - (m * (i - 1) / who);
				else ans -= (m * i) / who - (m * (i - 1)) / who;
			}
		}
	}
	cout << ans << endl;
}