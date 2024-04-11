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

const ll INF = 100000000000000000ll;

ll dp[200005][11];
int n;
VI cards[3];

std::vector<VI> moves = {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 0, 1}};


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, 200005) FOR(j, 11) dp[i][j] = -INF;
	dp[0][0] = 0;
	REP(i, 1, n+1){
		FOR(j, 3) cards[j].clear();
		int k;
		std::cin >> k;
		FOR(j, k){
			int c, d;
			std::cin >> c >> d;
			cards[c-1].push_back(d);
		}
		FOR(j, 3) std::sort(cards[j].begin(), cards[j].end(), std::greater<int>());
		TRAV(mv, moves){
			bool bad = false;
			VI cr;
			ll sum = 0;
			ll max = 0;
			FOR(j, 3){
				if(SZ(cards[j]) < mv[j]){
					bad = true;
					break;
				}
				FOR(l, mv[j]){
					cr.push_back(cards[j][l]);
					max = std::max(max, 1ll*cr.back());
					sum += cr.back();
				}
			}
			if(bad) continue;
			std::sort(cr.begin(), cr.end());
			FOR(j, 10){
				int last = j-SZ(cr);
				if(last < 0) last += 10;
				if(last > j){
					dp[i][j] = std::max(dp[i][j], dp[i-1][last]+sum+max);
				}else{
					dp[i][j] = std::max(dp[i][j], dp[i-1][last]+sum);
				}
			}
		}
	}
	ll max = 0;
	FOR(i, 10) max = std::max(max, dp[n][i]);
	std::cout << max;
	return 0;
}