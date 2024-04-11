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

int n;
int dp[1000005];
VI A;
const int MOD = 1000000007;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	dp[0] = 1;
	FOR(i, n){
		std::vector<int> divs;
		for(int j = 1; j*j <= A[i]; ++j){
			if(A[i]%j == 0){
				divs.push_back(j);
				if(j*j!=A[i]){
					dp[A[i]/j] = (dp[A[i]/j]+dp[A[i]/j-1])%MOD;
				}
			}
		}
		auto it = divs.end();
		while(it != divs.begin()){
			it--;
			dp[*it] = (dp[*it]+dp[*it-1])%MOD;			
		}
	}
	int ans = 0;
	REP(i, 1, 100005) ans = (ans+dp[i])%MOD;
	std::cout << ans << "\n";
	return 0;
}