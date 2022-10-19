#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;

int n, k, A[N], B[N], t;

long long dp[N];

void rmain() {
	scanf("%lld%lld", &n, &k);
	int ans = 0;
	
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]), ans += A[i];
	
	for(int i = 1; i <= n; ++ i) {
		B[i] = A[i] - (n - i);
	}
	
	sort(B + 1, B + n + 1);
	reverse(B + 1, B + n + 1);
	
	int res = ans;
	
	for(int i = 1; i <= k; ++ i) {
		res = res - B[i];
		res = res - (i - 1);
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	
}

main() {
	for(cin >> t; t --;) {
		rmain();
	}
}