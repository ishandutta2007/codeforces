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

ll dp[2][1<<7];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, p, k;
	std::cin >> n >> p >> k;
	VI A(n);
	std::vector<VI> P(n, VI(p));
	FOR(i, n) std::cin >> A[i];
	VI ind(n);
	FOR(i, n) ind[i] = i;
	std::sort(ind.begin(), ind.end(), [&](int a, int b){
		return A[a] > A[b];
	});
	FOR(i, n){
		FOR(j, p) std::cin >> P[i][j];
	}
	const ll INF = 1000000000ll*1000000000ll;
	FOR(i, 1<<p) dp[1][i] = -INF;
	dp[1][0] = 0;
	int i = 0;
	TRAV(a, ind){
		FOR(mask, 1<<p){
			dp[i&1][mask] = -INF;
			if(i+1 < __builtin_popcount(mask)){
				continue;
			}
			if(i>=__builtin_popcount(mask)){
				dp[i&1][mask] = dp[(i&1)^1][mask];
				if(i-__builtin_popcount(mask)+1 <= k) dp[i&1][mask] += A[a];
			}
			FOR(guy, p) if((1<<guy) & mask){
				dp[i&1][mask] = std::max(dp[i&1][mask], dp[(i&1)^1][mask^(1<<guy)]+P[a][guy]);
			}
		}
		i++;
	}
	std::cout << dp[(n-1)&1][(1<<p)-1];

	return 0;
}