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

int n, k, l;
VI pref;
VI A;
inline int sum(int a, int b){
	return pref[b+1]-pref[a];
}

PR<ll, int> withcost(int cost){
	std::vector<PR<ll, int> > dp(n+1);
	REP(i, 1, n+1){
		int b = std::max(0, i-l);
		dp[i] = std::min(MP(dp[b].X+cost, dp[b].Y+1),
						MP(dp[i-1].X+A[i-1], dp[i-1].Y));
	}
	return dp[n];
}

int aaa(int cost){
	return withcost(cost).X-1ll*k*cost;
}

int solve(){
	int left = 0;
	int right = 1000000000;
	while(left < right){
		int cost = (left+right)/2;
		auto xd = withcost(cost);
		if(xd.Y > k) left = cost+1;
		else right = cost;
	}
	return aaa(left);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> l;
	std::string s;
	std::cin >> s;
	A.resize(n);
	pref.resize(n+1);
	FOR(i, SZ(s)) if(s[i] < 'a') A[i] = 1;
	FOR(i, n) pref[i+1] = pref[i] + A[i];
	int ans = solve();
	FOR(i, n) A[i] = 1-A[i];
	FOR(i, n) pref[i+1] = pref[i] + A[i];
	ans = std::min(solve(), ans);
	std::cout << ans << "\n";
	return 0;
}