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

int dp[23][1005];

const int MOD = 1000000007;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	m *= 2;
	dp[0][1] = 1;
	REP(i, 1, m+1){
		REP(j, 1, n+1){
			dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
		}
	}
	int sum = 0;
	REP(j, 1, n+1) sum = (sum+dp[m][j])%MOD;
	std::cout << sum << "\n";
	
	return 0;
}