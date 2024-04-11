#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 5;
const int K = 5e3 + 5;

int dp[K][K], n, A[N], k;

int calc(int x) {
	if(x > n) return 0;
	return A[x] - A[x - 1];
}

main(void) {
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld", &A[i]);
	}
	
	int ans = 0;
	
	sort(A + 1, A + n + 1);
	
	for(int i = 1; i < n; ++ i) ans += abs(A[i] - A[i + 1]);
	
	if(n < k) {
		puts("0");
		return 0;
	}
	int S1 = n % k, S2 = k - S1;
	for(int i = 0; i <= S1; ++ i) {
		for(int j = 0; j <= S2; ++ j) dp[i][j] = 0;
	}
	dp[0][0] = 0;
	for(int i = 0; i <= S1; ++ i) {
		for(int j = 0; j <= S2; ++ j) {
			int beg = i * (n / k + 1) + j * (n / k) + 1;
			if(i < S1) {
				dp[i + 1][j] = max(calc(beg + (n / k) + 1) + dp[i][j], dp[i + 1][j]);
			}
			if(j < S2) {
				dp[i][j + 1] = max(calc(beg + n / k) + dp[i][j], dp[i][j + 1]);
			}
		}
	}
	cout << ans - dp[S1][S2] << endl;
}