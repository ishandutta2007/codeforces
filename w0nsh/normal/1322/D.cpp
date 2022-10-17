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

int dp[4005][2005];
const int INF = 1000000666;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m ;
	std::cin >> n >> m;
	m = n+m;
	VI L(n), S(n), C(m+1);
	FOR(i, n) std::cin >> L[i];
	FOR(i, n) std::cin >> S[i];
	FOR(i, m) std::cin >> C[i+1];
	std::reverse(L.begin(), L.end());
	std::reverse(S.begin(), S.end());
	FOR(i, m+1) FOR(j, n+1) dp[i][j] = -INF;
	FOR(i, n+1) dp[i][0] = 0;
	FOR(g, n){
		int l = L[g];
		int s = S[g];
		for(int i = n; i >= 1; --i) dp[l][i] = std::max(dp[l][i], dp[l][i-1]-s+C[l]);
		int ile = n;
		REP(x, l+1, m+1){
			FOR(i, ile+1){
				if(i*2 <= n) dp[x][i] = std::max(dp[x][i], dp[x-1][i*2]+i*C[x]);
				if(i*2+1 <= n) dp[x][i] = std::max(dp[x][i], dp[x-1][i*2+1]+i*C[x]);
			}
			ile = (ile+1)/2;
		}
	}
	int mx = 0;
	FOR(i, m+1) mx = std::max(mx, dp[i][1]);
	std::cout << mx;
	return 0;
}