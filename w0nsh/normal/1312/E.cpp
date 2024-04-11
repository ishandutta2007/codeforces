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

int can[505][505];
int dp[505];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) FOR(j, n) can[i][j] = -1;
	FOR(i, n) can[i][i] = A[i];
	for(int sz = 2; sz <= n; ++sz){
		FOR(l, n-sz+1){
			int r = l+sz-1;
			assert(r < n);
			REP(i, l, r){
				if(can[l][i] != -1 && can[l][i] == can[i+1][r]){
					assert(can[l][r] == -1 || can[l][r] == can[l][i]);
					can[l][r] = can[l][i]+1;
				}
			}
		}
	}
	FOR(i, n){
		dp[i] = 100000;
		for(int j = 0; j <= i; ++j){
			if(can[j][i] != -1){
				dp[i] = std::min(dp[i], (j == 0 ? 0 : dp[j-1])+1);
			}
		}
	}
	std::cout << dp[n-1];

	return 0;
}