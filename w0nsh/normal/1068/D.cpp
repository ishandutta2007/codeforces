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

const int MOD = 998244353;

int n;
int dp[100005][205][2];
int A[100005], pref[2][205];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) std::cin >> A[i+1];
	// 0 - cant go lower
	// 1 - can go lower
	dp[0][0][0] = 1;
	REP(i, 1, n+1){
		if(A[i] == -1){
			pref[0][200] = 0;
			for(int j = 199; j >= 1; --j){
				pref[0][j] = (pref[0][j+1] + dp[i-1][j+1][1])%MOD;
			}
			pref[1][0] = 0;
			for(int j = 1; j <= 200; ++j){
				pref[1][j] = ((pref[1][j-1] + dp[i-1][j-1][1])%MOD + dp[i-1][j-1][0]) %  MOD;
			}
			REP(which, 1, 201){
				dp[i][which][1] = ((dp[i][which][1]+dp[i-1][which][1])%MOD+dp[i-1][which][0])%MOD;
				dp[i][which][1] = (dp[i][which][1]+pref[0][which])%MOD;
				dp[i][which][0] = (dp[i][which][0]+pref[1][which])%MOD;
				// REP(j, 0, 201){
					// if(j > which) dp[i][which][1] = (dp[i][which][1]+dp[i-1][j][1])%MOD;
					// else if(j == which){
					//	dp[i][which][1] = (dp[i][which][1]+dp[i-1][j][1]+dp[i-1][j][0])%MOD;
					// }else{
						// dp[i][which][0] = (dp[i][which][0]+dp[i-1][j][1]+dp[i-1][j][0])%MOD;
					// }
				// }
			}
		}else{
			REP(j, 0, 201){
				if(j > A[i]) dp[i][A[i]][1] = (dp[i][A[i]][1]+dp[i-1][j][1])%MOD;
				else if(j == A[i]){
					dp[i][A[i]][1] = (dp[i][A[i]][1]+(dp[i-1][j][1]+dp[i-1][j][0])%MOD)%MOD;
				}else dp[i][A[i]][0] = ((dp[i][A[i]][0]+dp[i-1][j][1])%MOD+dp[i-1][j][0])%MOD;
			}
		}
	}
	if(A[n] != -1) std::cout << (dp[n][A[n]][1])%MOD << "\n";
	else{
		int ans = 0;
		REP(i, 1, 201) ans = (ans+dp[n][i][1])%MOD;
		std::cout << ans << "\n";
	}
	return 0;
}