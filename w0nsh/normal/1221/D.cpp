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

const ll INF = 1000000000ll*1000000000ll*2ll;
ll dp[300005][3];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		std::vector<PII> A(n+1);
		REP(i, 1, n+1){
			std::cin >> A[i].X >> A[i].Y;
		}
		FOR(i, n+1) FOR(j, 3) dp[i][j] = INF;
		FOR(i, 3) dp[0][i] = 0;
		REP(i, 1, n+1){
			FOR(j, 3){
				FOR(k, 3){
					int last = A[i-1].X+j;
					int now = A[i].X+k;
					if(last == now) continue;
					dp[i][k] = std::min(dp[i][k], dp[i-1][j]+1ll*k*A[i].Y);
				}
			}
		}
		ll min = INF;
		FOR(i, 3) min = std::min(min, dp[n][i]);
		std::cout << min << "\n";
	}
	return 0;
}