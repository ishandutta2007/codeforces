#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
 
int dp[5005][5005];
const int MOD = 1000000007;
int rz[5005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k, q;
	std::cin >> n >> k >> q;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	FOR(i, n) dp[0][i] = 1;
	REP(cz, 1, k+1){
		FOR(i, n){
			if(i > 0) dp[cz][i] = dp[cz-1][i-1];
			if(i < n-1) dp[cz][i] = (dp[cz][i] + dp[cz-1][i+1])%MOD;
		}
	}

	FOR(cz, k+1){
		FOR(i, n){
			rz[i] = (rz[i] + 1ll*dp[cz][i]*dp[k-cz][i])%MOD;
		}
	}

	int ans = 0;
	FOR(i, n){
		ans = (ans + 1ll*rz[i]*A[i])%MOD;
	}


	FOR(_, q){
		int ind, x;
		std::cin >> ind >> x;
		ind--;
		ans = (ans - 1ll*rz[ind]*A[ind])%MOD;
		A[ind]= x;
		ans = (ans + 1ll*rz[ind]*A[ind])%MOD;
		if(ans < 0) ans += MOD;
		std::cout << ans << "\n";
	}

	return 0;
}