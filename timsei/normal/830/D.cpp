#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 405;
const int mod = 1e9 + 7;

int dp[N][N] , n , m;

void Add(int &x , int y) {
	x += y;
}

signed main(void) {
	cin >> n;
	dp[1][1] = 1; dp[1][0] = 1;
	for(register int i = 1;i < n;++ i) {
		for(register int j = 0;j <= n;++ j) {
			for(register int k = j;k <= n && j + k + i <= n + 1;++ k) {
				int now = dp[i][j] * dp[i][k] % mod;
				now = now << (k != j);
				if(!now) continue;
				Add(dp[i + 1][j + k] , now);
				Add(dp[i + 1][j + k + 1] , now);
				Add(dp[i + 1][j + k] , now * 2 * (k + j));
				if(j|k)Add(dp[i + 1][j + k - 1] , now * (k + j) * (k + j - 1));
			}
			for(register int k = 1;k <= n;++ k) dp[i + 1][k] %= mod;
		}
	}
	cout << dp[n][1];
}