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

const int MOD = 1000000007;

int n, k;
std::vector<VI> g;
std::vector<bool> vis;

int dfs(int v){
	vis[v] = true;
	int ret = 0;
	TRAV(ch, g[v]){
		if(vis[ch]) continue;
		ret += dfs(ch);
	}
	return ret+1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	vis.resize(n);
	g.resize(n);
	FOR(i, n-1){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		if(c == 0){
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}
	int ans = 1;
	FOR(i, k) ans = (1ll*ans*n)%MOD;
	FOR(i, n){
		if(vis[i]) continue;
		int ile = dfs(i);
		int cur = 1;
		FOR(j, k) cur = (1ll*ile*cur)%MOD;
		ans = (ans-cur)%MOD;
		if(ans < 0) ans += MOD;
	}
	std::cout << ans;
	return 0;
}