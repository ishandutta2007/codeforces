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

int n, k;
int tab[100][100];
int col[100];
int dp[100][11];
const int INF = 1000000005;

int main(){
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> los(0, 1);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	FOR(i, n) FOR(j, n) std::cin >> tab[i][j];
	int ans = INF;
	FOR(_, 2000){
		FOR(i, n) col[i] = los(rng);
		FOR(i, n) FOR(j, k+1) dp[i][j] = INF;
		dp[0][0] = 0;
		REP(t, 1, 11){
			FOR(i, n) FOR(j, n) if(col[i] != col[j]){
				dp[i][t] = std::min(dp[i][t], dp[j][t-1]+tab[i][j]);
			}
		}
		ans = std::min(ans, dp[0][k]);
	}
	std::cout << ans << "\n";
	
	return 0;
}