#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int MOD = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){

		int n, k;
		std::cin >> n >> k;
		int ans = 0;
		int pw = 1;
		FOR(i, 30){
			if(k & (1<<i)){
				ans = (ans + pw) % MOD;
			}
			pw = (1ll * pw * n) % MOD;
		}

		std::cout << ans << "\n";

	}

	return 0;
}