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

std::vector<VI> g;
VI lev, sz;

void dfs(int v, int par=-1){
	sz[v] = 1;
	TRAV(ch, g[v]) if(ch != par){
		lev[ch] = lev[v]+1;
		dfs(ch, v);
		sz[v] += sz[ch];
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	g.resize(n);
	lev.resize(n);
	sz.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	VI val(n);
	FOR(i, n) val[i] = lev[i]-sz[i]+1;
	std::sort(val.begin(), val.end());
	std::reverse(val.begin(), val.end());
	ll ans = 0;
	FOR(i, k) ans += val[i];
	std::cout << ans << "\n";
	return 0;
}