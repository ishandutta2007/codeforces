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

int n;
std::vector<VI> g;
VI col;
VI dp, dp2;

void dfs(int v, int par=-1){
	int ans = col[v];
	TRAV(ch, g[v]) if(ch != par){
		dfs(ch, v);
		ans += std::max(0, dp[ch]);
	}
	dp[v] = ans;
}

void dfs2(int v, int par=-1){
	if(par == -1) dp2[v] = 0;
	else dp2[v] = std::max(0, dp2[par]+col[par]+std::max(dp[par]-col[par]-std::max(0, dp[v]), 0));
	TRAV(ch, g[v]) if(ch != par){
		dfs2(ch,v);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	col.resize(n);
	dp.resize(n);
	dp2.resize(n);
	g.resize(n);
	FOR(i, n) std::cin >> col[i];
	FOR(i, n) if(col[i] == 0) col[i] = -1;
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	dfs2(0);
	FOR(i, n) std::cout << dp[i]+dp2[i] << " ";
	return 0;
}