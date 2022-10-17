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

const int MOD = 1000000007;
int dp[200005][3];
int num[3];
int n, l, r;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> l >> r;
	dp[0][0] = 1;
	FOR(i, 3){
		int cr = l;
		while(cr % 3 != i) cr++;
		int en = r;
		while(cr % 3 != i) en--;
		if(cr <= en) num[i] = (en-cr)/3 + 1;
	}
	REP(i, 1, n+1){
		dp[i][0] = (1ll*dp[i-1][0]*num[0])%MOD;
		dp[i][0] = (1ll*dp[i][0] + 1ll*dp[i-1][2]*num[1])%MOD;
		dp[i][0] = (1ll*dp[i][0] + 1ll*dp[i-1][1]*num[2])%MOD;

		dp[i][1] = (1ll*dp[i-1][1]*num[0])%MOD;
		dp[i][1] = (1ll*dp[i][1] + 1ll*dp[i-1][2]*num[2])%MOD;
		dp[i][1] = (1ll*dp[i][1] + 1ll*dp[i-1][0]*num[1])%MOD;

		dp[i][2] = (1ll*dp[i-1][2]*num[0])%MOD;
		dp[i][2] = (1ll*dp[i][2] + 1ll*dp[i-1][0]*num[2])%MOD;
		dp[i][2] = (1ll*dp[i][2] + 1ll*dp[i-1][1]*num[1])%MOD;
	}
	std::cout << dp[n][0];
	return 0;
}