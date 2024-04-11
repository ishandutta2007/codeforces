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
typedef double ld;

int n, a, b;
ld p[2005], u[2005];

PR<ld, int> dp[2005][2005];

PR<ld, int> check(ld pen){
	FOR(i, a+1) dp[0][i] = MP(0.0, 0);
	REP(i, 1, n+1){
		REP(j, 0, a+1){
			dp[i][j] = dp[i-1][j];
			dp[i][j] = std::max(dp[i][j], MP(dp[i-1][j].X+u[i]-pen, dp[i-1][j].Y+1));
			if(j > 0){
				dp[i][j] = std::max(dp[i][j], MP(dp[i-1][j-1].X+p[i], dp[i-1][j-1].Y));
				dp[i][j] = std::max(dp[i][j], MP(dp[i-1][j-1].X+p[i]+u[i]-p[i]*u[i]-pen, dp[i-1][j-1].Y+1));
			}
		}
	}
	return dp[n][a];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> a >> b;
	REP(i, 1, n+1) std::cin >> p[i];
	REP(i, 1, n+1) std::cin >> u[i];
	ld left = 0.0;
	ld right = 1e18;
	while(right-left > 0.00000001){
		ld pen = (left+right)/2;
		if(check(pen).Y > b) left = pen;
		else right = pen;
	}
	std::cout << std::fixed << std::setprecision(12) << check(right).X + right*b << "\n";
	return 0;
}