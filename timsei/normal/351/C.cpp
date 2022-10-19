#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
const int M = 25;

int A[M], B[M], n, m, x, y, cnt;
int dp[M * 4][M * 4]; 

void Min(int &x, int y) {
	x = min(x, y);
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++ i) cin >> A[i];
	for(int i = 0; i < n; ++ i) cin >> B[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 0; i < n * 4; ++ i) {
		for(int j = 0; j <= n + n; ++ j) 
		if(dp[i][j] <= 1e9) {
			Min(dp[i + 1][j + 1], dp[i][j] + A[i % n]);
			if(j) Min(dp[i + 1][j - 1], dp[i][j] + B[i % n]);
		}
	}
	if(m <= 3) cout << dp[n * m][0] << endl;
	else cout << dp[n * 4][0] + (m - 4) / 2 * (dp[n * 4][0] - dp[n * 2][0]) << endl;
}