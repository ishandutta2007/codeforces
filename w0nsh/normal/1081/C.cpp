#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

const int MOD = 998244353;

int n, m, k;
int dp[2050][2050];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	dp[1][0] = m;
	REP(i, 2, n+1){
		REP(j, 0, k+1){
			if(j == 0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = (1ll*dp[i-1][j]+1ll*(m-1)*dp[i-1][j-1])%MOD;
		}
	}
	std::cout << dp[n][k];
	return 0;
}