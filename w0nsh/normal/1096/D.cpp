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

const ll INF = 1000000000ll*1000000000ll;
ll n, dp[4][100005];
std::vector<ll> S, A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	std::string xd;
	std::cin >> xd;
	FOR(i, n){
		if(xd[i] == 'h') S.push_back(0);
		else if(xd[i] == 'a') S.push_back(1);
		else if(xd[i] == 'r') S.push_back(2);
		else if(xd[i] == 'd') S.push_back(3);
		else S.push_back(-1);
	}
	FOR(i, n) std::cin >> A[i];
	FOR(i, 4) FOR(j, 100005) dp[i][j] = INF;
	FOR(j, 4) dp[j][0] = 0;
	REP(i, 1, n+1){
		if(S[i-1] == -1){
			FOR(j, 4) dp[j][i] = dp[j][i-1];
		}else{
			FOR(j, S[i-1]) dp[j][i] = dp[j][i-1];
			REP(j, S[i-1]+1, 4) dp[j][i] = dp[j][i-1];
			FOR(j, S[i-1]) dp[S[i-1]][i] = std::min(dp[S[i-1]][i], dp[j][i-1]);
			dp[S[i-1]][i] = std::min(dp[S[i-1]][i], dp[S[i-1]][i-1]+A[i-1]);
		}
	}
	ll min = INF;
	FOR(i, 4) min = std::min(min, dp[i][n]);
	std::cout << min << "\n";
	return 0;
}