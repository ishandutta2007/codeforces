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

typedef std::bitset<512> BS;

BS dp[505];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;

	dp[0][0] = true;

	FOR(i, n){
		int c;
		std::cin >> c;

		for(int j = k; j >= c; --j){
			dp[j] = dp[j]|(dp[j-c] << c)|dp[j-c];
		}
	}

	VI ans;
	FOR(i, k+1) if(dp[k][i]) ans.push_back(i);

	std::cout << SZ(ans ) << "\n";
	TRAV(i, ans) std::cout << i << " ";

	return 0;
}