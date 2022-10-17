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

ll dp[105][105][105];
const ll INF = 1000000000ll*1000000000ll;
int cost[105][105];
PII mn[105][105];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, k;
	std::cin >> n >> m >> k;
	VI col(n);
	FOR(i, n) std::cin >> col[i];
	FOR(i, n) FOR(j, m){
		std::cin >> cost[i][j];
	}
	FOR(i, n+1) FOR(j, k+1) FOR(l, m+1) dp[i][j][l] = INF, mn[i][j] = MP(0, 0);
	dp[0][0][0] = 0;
	mn[0][0] = MP(0, 1);
	REP(i, 1, n+1){
		REP(j, 1, k+1){
			if(col[i-1] != 0){
				int dif = mn[i-1][j-1].X;
				if(dif == col[i-1]) dif = mn[i-1][j-1].Y;
				if(dif == col[i-1]) dif = -1;
				dp[i][j][col[i-1]] = std::min(INF, std::min(dp[i-1][j][col[i-1]], (dif == -1 ? INF : dp[i-1][j-1][dif])));
				mn[i][j].X = col[i-1];
			}else{
				REP(l, 1, m+1){
					int dif = mn[i-1][j-1].X;
					if(dif == l) dif = mn[i-1][j-1].Y;
					if(dif == l) dif = -1;
					dp[i][j][l] = std::min(INF, 1ll*cost[i-1][l-1] + std::min(dp[i-1][j][l], (dif == -1 ? INF : dp[i-1][j-1][dif])));
					if(dp[i][j][mn[i][j].X] > dp[i][j][l]){
						std::swap(mn[i][j].X, mn[i][j].Y);
						mn[i][j].X = l;
					}else if(dp[i][j][mn[i][j].Y] > dp[i][j][l]){
						mn[i][j].Y = l;
					}
				}
			}
		}
	}/*
	FOR(i, n+1){
		FOR(j, k+1){
			std::cout << dp[i][j][col[i-1]] << " ";
		}
		std::cout << "\n";
	}*/
	if(dp[n][k][mn[n][k].X] == INF) std::cout << -1 << "\n";
	else std::cout << dp[n][k][mn[n][k].X] << "\n";
	return 0;
}