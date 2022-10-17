#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int tab[13][2005];
int nt[13][12];
int dp[13][1<<12];
int cur[1<<12];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		FOR(i, n){
			FOR(j, m){
				std::cin >> tab[i+1][j+1];
			}
		}
		std::vector<PII> vec;
		REP(j,1,  m+1){
			int mx = 0;
			REP(i,1, n+1) mx = std::max(mx, tab[i][j]);
			vec.push_back(MP(mx, j));
		}
		std::sort(vec.begin(), vec.end());
		std::reverse(vec.begin(), vec.end());
		m = std::min(m, n);
		REP(j, 1, m+1){
			REP(i, 1, n+1) nt[i][j] = tab[i][vec[j-1].Y];
		}
		REP(i, 0, m+1) FOR(j, (1<<n)) dp[i][j] = 0;
		REP(j, 1, m+1){
			FOR(_, n){
				FOR(mask, 1<<n) cur[mask] = dp[j-1][mask];
				FOR(mask, 1<<n){
					REP(i, 1, n+1) if(mask & (1<<(i-1))){
						cur[mask] = std::max(cur[mask], cur[mask^(1<<(i-1))]+nt[i][j]);
					}
				}
				FOR(mask, 1<<n) dp[j][mask] = std::max(dp[j][mask], cur[mask]);
				REP(i, 1, n) std::swap(nt[i][j], nt[i+1][j]);
			}	
		}
		std::cout << dp[m][(1<<n)-1] << "\n";
	}
	return 0;
}