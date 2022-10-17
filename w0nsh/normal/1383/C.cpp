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

int dag(std::vector<VI> g, VI wierz){
	std::sort(wierz.begin(), wierz.end());
	auto kto = [&](int v){
		assert(std::find(wierz.begin(), wierz.end(), v) != wierz.end());
		return std::lower_bound(wierz.begin(), wierz.end(), v)-wierz.begin();
	};

	int n = SZ(wierz);
	VI dp(1<<n);
	VI hehe(n);
	FOR(i, n) TRAV(j, g[wierz[i]]) hehe[i] |= (1<<kto(j));

	int best = 0;
	dp[0] = 1;
	REP(mask, 1, 1<<n){
		FOR(i, n) if(mask & (1<<i)){
			dp[mask] |= dp[mask ^ (1<<i)] & ((hehe[i] & mask) == 0);
		}
		if(dp[mask]) best = std::max(best, __builtin_popcount(mask));
	}

	return best;
}

void solve(std::vector<VI> g, std::vector<VI> gg){
	std::vector<bool> vis(20);
	VI cur;
	std::function<void(int)> dfs = [&](int v){
		vis[v] = true;
		cur.push_back(v);
		TRAV(ch, gg[v]) if(!vis[ch]) dfs(ch);
	};

	int ans = 0;

	FOR(i, 20) if(!vis[i]){
		cur.clear();
		dfs(i);

		ans += 2*SZ(cur)-1 - dag(g, cur);
	}

	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::string a, b;
		std::cin >> a >> b;
		std::vector<VI> g(20);
		std::vector<VI> gg(20);
		FOR(i, n){
			if(a[i] != b[i]){
				g[a[i]-'a'].push_back(b[i]-'a');
				gg[a[i]-'a'].push_back(b[i]-'a');
				gg[b[i]-'a'].push_back(a[i]-'a');
			}
		}
		solve(g, gg);
	}

	return 0;
}