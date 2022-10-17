#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, k, x;
VI A;
ll dp[5005][5005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> x;
	A.resize(n+1);
	FOR(i, n) std::cin >> A[i+1];
	REP(i, 1, n+1){
		if(i <= k) dp[i][1] = A[i];
		REP(pl, 1, k+1) REP(j, 1, i) if(i-pl >= 1 && dp[i-pl][j] > 0)
			dp[i][j+1] = std::max(dp[i][j+1], dp[i-pl][j] + A[i]);
	}
	ll mx = 0;
	FOR(i, k) mx = std::max(mx, dp[n-i][x]);
	if(mx == 0) std::cout << -1 << "\n";
	else std::cout << mx << "\n";
	return 0;
}