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

int n;
std::vector<VI> g;
std::vector<VI> levs;
std::vector<ll> A;

void dfs(int v, int par=-1, int lev=-1){
	if(lev >= 0){
		if(SZ(levs) <= lev) levs.emplace_back();
		levs[lev].push_back(v);
	}
	TRAV(ch, g[v]) if(ch != par){
		dfs(ch, v, lev+1);
	}
}

void solve(){
	levs = std::vector<VI>();
	dfs(0);
	std::vector<ll> dp(n);
	const ll INF = 1000000000ll*1000000666ll;
	for(int d = SZ(levs)-1; d >= 0; --d){
		ll lef_a = -INF;
		ll rig_a = -INF;
		ll lef_b = -INF;
		ll rig_b = -INF;
		TRAV(v, levs[d]){
			lef_a = std::max(lef_a, A[v]);
			rig_a = std::max(rig_a, -A[v]);
			ll best = 0;
			TRAV(ch, g[v]) best = std::max(best, dp[ch]);
			lef_b = std::max(lef_b, A[v] + best);
			rig_b = std::max(rig_b, -A[v] + best);
		}
		TRAV(v, levs[d]){
			ll best = 0;
			TRAV(ch, g[v]) best = std::max(best, dp[ch]);
			dp[v] = A[v] + best + rig_a;
			dp[v] = std::max(dp[v], -A[v] + best + lef_a);
			dp[v] = std::max(dp[v], A[v] + rig_b);
			dp[v] = std::max(dp[v], -A[v] + lef_b);
		}
	}
	std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n;
		g = std::vector<VI>(n);
		A.resize(n);
		FOR(i, n-1){
			int a;
			std::cin >> a;
			a--;
			g[a].push_back(i+1);
		}
		FOR(i, n-1) std::cin >> A[i+1];
		solve();
	}

	return 0;
}