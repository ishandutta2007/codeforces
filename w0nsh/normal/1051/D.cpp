#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 998244353;
unsigned n, k, dp[1005][2005][2][2];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	dp[0][1][0][0] = 1;
	dp[0][1][1][1] = 1;
	dp[0][2][0][1] = 1;
	dp[0][2][1][0] = 1;
	REP(i, 1, n) REP(j, 1, k+1){
		dp[i][j][0][0] += dp[i-1][j][0][0] + dp[i-1][j][0][1] + dp[i-1][j][1][0] + dp[i-1][j-1][1][1];
		dp[i][j][1][1] += dp[i-1][j][1][1] + dp[i-1][j][0][1] + dp[i-1][j][1][0] + dp[i-1][j-1][0][0];
		dp[i][j][0][1] += dp[i-1][j][0][1] + dp[i-1][j-1][0][0] + dp[i-1][j-1][1][1] + (j-2 >= 0 ? dp[i-1][j-2][1][0] : 0);
		dp[i][j][1][0] += dp[i-1][j][1][0] + dp[i-1][j-1][0][0] + dp[i-1][j-1][1][1] + (j-2 >= 0 ? dp[i-1][j-2][0][1] : 0);
		dp[i][j][0][0] %= MOD;
		dp[i][j][1][1] %= MOD;
		dp[i][j][0][1] %= MOD;
		dp[i][j][1][0] %= MOD;
	}
	std::cout << (dp[n-1][k][0][0]+dp[n-1][k][1][1]+dp[n-1][k][0][1]+dp[n-1][k][1][0])%MOD << "\n";
	return 0;
}