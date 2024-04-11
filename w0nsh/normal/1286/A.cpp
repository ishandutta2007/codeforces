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

const int INF = 1000000000;
int dp[105][105][105][2];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	FOR(i, n+1) FOR(j, n+1) FOR(k, n+1) FOR(xd, 2) dp[i][j][k][xd] = INF;
	dp[0][0][0][0] = 0;
	dp[0][0][0][1] = 0;
	REP(i, 1, n+1){
		FOR(j, n+1){
			FOR(k, n+1){
				if(A[i-1] == 0 || A[i-1]%2 == 0){
					if(j > 0) dp[i][j][k][0] = std::min(dp[i-1][j-1][k][1]+1,
											dp[i-1][j-1][k][0]);
				}
				if(A[i-1] == 0 || A[i-1]%2 == 1){
					if(k > 0) dp[i][j][k][1] = std::min(dp[i-1][j][k-1][1],
										dp[i-1][j][k-1][0]+1);
				}
			}
		}
	}
	std::cout << std::min(dp[n][n/2][(n+1)/2][0], dp[n][n/2][(n+1)/2][1]) << "\n";
	return 0;
}