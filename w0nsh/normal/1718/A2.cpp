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

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::map<int, int> dp;
	dp[0] = 0;
	int pref = 0;
	int mx = 0;
	FOR(i, n){
		pref ^= A[i];
		int cand = mx;
		if(dp.count(pref)) cand = std::max(cand, dp[pref] + 1);
		mx = std::max(mx, cand);
		dp[pref] = cand;
	}

	int ans = 0;
	TRAV(xd, dp) ans = std::max(ans, xd.Y);
	std::cout << n - ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}