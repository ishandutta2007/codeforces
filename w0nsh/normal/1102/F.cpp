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

const int INF = 2000000777;
int n, m;
int tab[20][10004];
int cost[17][17];
int endcost[17][17];
int dp[16][16][70000];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, 17) FOR(j, 17) cost[i][j] = endcost[i][j] = INF;
	FOR(i, n) FOR(j, m) std::cin >> tab[i][j];
	FOR(i, n) FOR(j, n){
		FOR(k, m-1) endcost[i][j] = std::min(endcost[i][j], std::abs(tab[i][k]-tab[j][k+1]));
		if(i == j) continue;
		FOR(k, m) cost[i][j] = std::min(cost[i][j], std::abs(tab[i][k]-tab[j][k]));
	}
	if(n == 1){
		std::cout <<  endcost[0][0];
		return 0;
	}

	FOR(i, n) dp[i][i][1<<i] = INF;
	FOR(mask, 1<<n){
		if(mask == ((1<<n)-1)){
			int best = 0;
			FOR(i, n) FOR(j, n){
				if(i == j) continue;
				best = std::max(best, std::min(dp[i][j][mask], endcost[i][j]));
			}
			std::cout << best;
			return 0;
		}
		FOR(i, n) FOR(j, n){
			if(!((1<<i) & mask) || !((1<<j) & mask)) continue;
			FOR(k, n){
				if((1<<k) & mask) continue;
				if(i == j) dp[i][k][mask|(1<<k)] = std::max(dp[i][k][mask|(1<<k)],
							std::min(dp[i][i][mask], cost[i][k]));
				else dp[i][k][mask|(1<<k)] = std::max(dp[i][k][mask|(1<<k)],
							std::min(dp[i][j][mask], cost[j][k]));
			}
		}
	}
	return 0;
}