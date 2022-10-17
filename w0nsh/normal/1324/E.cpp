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

int dp[2005][2005];
int A[2005];
const int INF = 1000000666;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, h, l, r;
	std::cin >> n >> h >> l >> r;
	REP(i, 1, n+1) std::cin >> A[i];
	FOR(i, n+1) FOR(j, h) dp[i][j] = -INF;
	dp[0][0] = 0;
	auto bonus = [&](int bgc){
		return (int)(bgc >= l && bgc <= r);
	};
	REP(i, 1, n+1){
		FOR(j, h){
			dp[i][j] = std::max(dp[i][j], dp[i-1][(j-A[i]+h)%h] + bonus(j));
			dp[i][j] = std::max(dp[i][j], dp[i-1][(j-(A[i]-1)+h)%h] + bonus(j));
		}
	}
	int mx = 0;
	FOR(i, h) mx = std::max(dp[n][i], mx);
	std::cout << mx << "\n";
	return 0;
}