#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int n, m, x, y, A[N];

main() {
int ttt;
	for(cin >> ttt; ttt --;) {
		scanf("%lld%lld", &n, &x);
		for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
		int ans = 0, mn = A[1], mx = A[1];
		for(int i = 2; i <= n; ++ i) {
			mn = min(mn, A[i]);
			mx = max(mx, A[i]);
			if(mx - mn <= 2 * x) continue;
			else ++ ans, mn = A[i], mx = A[i];
		}
		printf("%lld\n", ans);
	}
}