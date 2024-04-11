#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int dp[2005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n*2);
		FOR(i, n*2) std::cin >> A[i];

		FOR(i, n+1) dp[i] = 0;
		dp[0] = 1;

		VI B;
		int have = 1;
		int best = A[0];
		REP(i, 1, 2*n){
			if(A[i] > best){
				B.push_back(have);
				best = A[i];
				have = 1;
			}else have++;
		}
		B.push_back(have);

		TRAV(i, B){
			for(int j = n; j >= i; --j){
				dp[j] = dp[j] || dp[j-i];
			}
		}

		if(dp[n]) std::cout << "YES\n";
		else std::cout << "NO\n";

	}

	return 0;
}