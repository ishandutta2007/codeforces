#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int dp[5005][5005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	std::string a, b;
	std::cin >> a >> b;
	a = "%" + a;
	b = "%" + b;
	int ans = 0;
	REP(i, 1, n+1){
		REP(j, 1, m+1){
			if(a[i] == b[j])
				dp[i][j] = std::max(dp[i][j], dp[i-1][j-1] + 2);
			dp[i][j] = std::max(dp[i][j], dp[i-1][j] - 1);
			dp[i][j] = std::max(dp[i][j], dp[i][j-1] - 1);
			ans = std::max(ans, dp[i][j]);
		}
	}
	std::cout << ans << "\n";
	return 0;
}