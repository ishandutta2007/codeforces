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

int right[505][505];
int down[505][505];
int dp[505][505][12];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, k;
	std::cin >> n >> m >> k;

	if(k%2){
		FOR(i, n){
			FOR(j, m){
				std::cout << -1 << " ";
			}
			std::cout << "\n";
		}
		return 0;
	}

	k /= 2;

	FOR(i, n){
		FOR(j, m-1){
			std::cin >> right[i][j];
		}
	}
	FOR(i, n-1){
		FOR(j, m){
			std::cin >> down[i][j];
		}
	}

	int INF = 1000000666;
	REP(s, 1, k+1){
		FOR(i, n){
			FOR(j, m){
				dp[i][j][s] = INF;
				if(i > 0)
					dp[i][j][s] = std::min(dp[i][j][s], dp[i-1][j][s-1] + 2*down[i-1][j]);
				if(i < n-1)
					dp[i][j][s] = std::min(dp[i][j][s], dp[i+1][j][s-1] + 2*down[i][j]);
				if(j > 0)
					dp[i][j][s] = std::min(dp[i][j][s], dp[i][j-1][s-1] + 2*right[i][j-1]);
				if(j < m-1)
					dp[i][j][s] = std::min(dp[i][j][s], dp[i][j+1][s-1] + 2*right[i][j]);

			}
		}
	}

	FOR(i, n){
		FOR(j, m){
			std::cout << dp[i][j][k] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}