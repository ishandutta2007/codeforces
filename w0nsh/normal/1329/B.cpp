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


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int d, m;
		std::cin >> d >> m;
		VI cnt;
		FOR(i, 30){
			int a = (1<<i);
			int b = (1<<(i+1)) - 1;
			int c = std::min(b, d);
			cnt.push_back(c-a+1);
			if(d == c) break;
		}

		cnt.push_back(1);
		
		VI dp(SZ(cnt)+1);
		dp[0] = 1;
		REP(i, 1, SZ(cnt)+1){
			FOR(j, i) dp[i] = (dp[i] + dp[j]) % m;
			dp[i] = (1ll * dp[i] * cnt[i-1]) % m;
		}

		dp.back() = (dp.back() - 1 + m) % m;

		std::cout << dp.back() << "\n";
	}

	return 0;
}