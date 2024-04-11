#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, k;
std::vector<VI> g;
std::vector<bool> vis(n);

int dfs(int v){
	vis[v] = true;
	int ans = 1;
	TRAV(ch, g[v]){
		if(!vis[ch]) ans += dfs(ch);
	}
	return ans;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	g.resize(n);
	FOR(i, k){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vis.resize(n);
	int ans = 0;
	FOR(i, n) if(!vis[i]){
		ans += dfs(i)-1;
	}
	std::cout << k-ans;
	return 0;
}