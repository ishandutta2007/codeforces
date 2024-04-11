#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 998244353;

std::string s, t, str;
int n, m;
int dp[3005][3005];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> s >> t;
	str = s;
	std::reverse(str.begin(), str.end());
	n = SZ(s);
	m = SZ(t);
	
	FOR(i, m+1) dp[0][i] = 1;
	int ans = 0;
	REP(i, 1, n+1){
		FOR(j, m){
			if(s[i-1] == t[j]) dp[i][j] = (dp[i][j]+dp[i-1][j+1])%MOD;
			int mam = i-1;
			int pos = j+mam;
			if(pos >= m || s[i-1] == t[pos]) dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
		}
		dp[i][m] = (dp[i-1][m]+dp[i-1][m])%MOD;
		if(i >= m){
	//		std::cout << i << " " << dp[i][0] << std::endl;
			ans = (ans+dp[i][0])%MOD;
		}
	}
	std::cout << ans << "\n";

	return 0;
}