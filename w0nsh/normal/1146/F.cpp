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

constexpr int MOD = 998244353;
std::vector<VI> g;

PII calculate(const std::vector<PII>& vec){
	assert(!vec.empty());
	VI dp{vec[0].X, vec[0].Y, 0};
	REP(i, 1, SZ(vec)){
		auto ch = vec[i];
		VI nxt{0, 0, 0};
		nxt[0] = (1ll * dp[0] * ch.X) % MOD;
		nxt[1] = (1ll * dp[0] * ch.Y + 1ll * dp[1] * ch.X) % MOD;
		nxt[2] = (1ll * dp[1] * ch.Y + 1ll * dp[2] * (ch.X + ch.Y)) % MOD;
		dp = nxt;
	}

	return {(dp[0] + dp[2]) % MOD, (dp[1] + dp[2]) % MOD};
}

PII dfs(int v){
	std::vector<PII> vec;
	vec.reserve(SZ(g[v]));
	TRAV(ch, g[v]){
		vec.push_back(dfs(ch));
	}

	if(vec.empty()){
		return {1, 1};
	}
	return calculate(vec);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	g.resize(n);
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		g[a].push_back(i+1);
	}

	auto[ans, ignore] = dfs(0);
	std::cout << ans << "\n";

	return 0;
}