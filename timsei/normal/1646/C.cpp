#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N = 1e6 + 5;

int n, s, t, A[N], fac[N];

int bc(int x) {
	if(!x) return 0;
	return (x & 1) + bc(x >> 1);
}

main() {
	fac[0] = 1;
	for(int i = 1; i <= 14; ++ i) fac[i] = i * fac[i - 1];
	for(cin >> t; t --;) {
		scanf("%lld", &n);
		int ans = 1e9, now, res;
		for(int i = 0; i < (1 << 14); ++ i) {
			now = n; res = 0;
			for(int j = 1; j <= 14; ++ j) {
				if((i >> (j - 1)) & 1) {
					now -= fac[j];
					++ res;
				}
			}
			if(now < 0) continue;
			res += bc(now);
			ans = min(ans, res);
		}
		cout << ans << endl;
	}
}