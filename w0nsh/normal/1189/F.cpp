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

const int MOD = 998244353;

int n, k;
VI A;

int binco[1005][1005];
int dp[1005][1005], dp2[1005][1005];

int get(int r){
	if((k-1)*r > 100005) return 0;
	FOR(i, n+1){
		FOR(j, k+1){
			dp[i][j] = 0;
			dp2[i][j] = 0;
		}
	}
	VI next(n);
	int right = 0;
	FOR(i, n){
		while(right < n && A[right] - A[i] < r) right++;
		next[i] = right;
	}
	int ans = 0;
	dp[n][0] = 1;
	for(int i = n-1; i >= 0; --i){
		REP(j, 0, k+1){
			dp[i][j] = ((j == 0 ? 0 : dp[next[i]][j-1])+dp[i+1][j])%MOD;
		}
		// ans = (ans+dp[next[i]][k-1])%MOD;
	}
	return dp[0][k];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	// FOR(i, n+1) binco[i][0] = binco[i][i] = 1;
	// REP(i, 1, n+1){
	// 	REP(j, 1, i){
	// 		binco[i][j] = (binco[i-1][j-1]+binco[i-1][j])%MOD;
	// 	}
	// }
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	int ans = 0;
	REP(i, 1, 100002) ans = (ans+get(i))%MOD;
	std::cout << ans;
	return 0;
}