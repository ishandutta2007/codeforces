#include <bits/stdc++.h>
using namespace std;

const int N = 25 + 5;

int t, n, A[N], B[N];
long long dp[N][2];
long long ans;

int calc(int i, int a, int b) {
	if(a ^ b) {
		return abs(A[i + 1] - B[i]) + abs(A[i] - B[i + 1]);
	} else {
		return abs(A[i + 1] - A[i]) + abs(B[i + 1] - B[i]);
	}
}

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++ i) scanf("%d", &B[i]);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i < n; ++ i) {
		dp[i + 1][0] = dp[i + 1][1] = 1e18;
		for(int a = 0; a < 2; ++ a) {
			for(int b = 0; b < 2; ++ b) {
				dp[i + 1][b] = min(dp[i + 1][b], dp[i][a] + calc(i, a, b));
			}
		}
	}
	cout << max(dp[n][1], dp[n][0]) << endl;
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}