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

ll cost[25][25];
ll dp[25][1<<20];

const ll INF = 1000000000*100000000ll;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i]--;
	VI ile(20);
	FOR(i, n){
		ile[A[i]]++;
		FOR(j, 20) if(j != A[i]){
			cost[A[i]][j] += ile[j];
		}
	}
	//FOR(i, 20) FOR(j, 20) std::cout << i << " , " << j << ": " << cost[i][j] << "\n";
	FOR(i, 20+1) FOR(mask, (1<<20)) dp[i][mask] = INF;
	dp[0][0] = 0;
	REP(i, 1, 20+1){
		FOR(mask, (1<<20)) if(__builtin_popcount(mask) == i){
			FOR(j, 20) if((1<<j) & mask){
				ll c = 0;
				int his = mask ^ (1<<j);
				FOR(k, 20) if((1<<k) & his) c += cost[k][j];
				dp[i][mask] = std::min(dp[i][mask], dp[i-1][his]+c);
			}
		}
	}
	std::cout << dp[20][(1<<20)-1] << "\n";
	return 0;
}