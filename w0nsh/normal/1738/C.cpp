#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int dp[105][105][2][2];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	constexpr int N = 104;
	dp[0][0][0][0] = dp[0][0][0][1] = 1;
	FOR(i, N) FOR(j, N) FOR(pr, 2) FOR(mv, 2){
		if(i == 0 && j == 0) continue;
		if(mv == 0){
			if(i) dp[i][j][pr][mv] |= dp[i-1][j][pr][mv^1];
			if(j) dp[i][j][pr][mv] |= dp[i][j-1][pr^1][mv^1];
		}else{
			dp[i][j][pr][mv] = 1;
			if(i) dp[i][j][pr][mv] &= dp[i-1][j][pr][mv^1];
			if(j) dp[i][j][pr][mv] &= dp[i][j-1][pr][mv^1];
		}
	}

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI cnt(2);
		FOR(i, n){
			int a;
			std::cin >> a;
			cnt[(a + 1000000000) % 2]++;
		}
		std::cout << (dp[cnt[0]][cnt[1]][0][0] ? "Alice\n" : "Bob\n");
	}

	return 0;
}