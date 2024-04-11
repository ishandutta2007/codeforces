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

std::vector<VI> g;
int par[20][100005];
int lev[100005];
void dfs(int v, int parent=-1){
	par[0][v] = parent;
	TRAV(ch, g[v]) if(ch != parent) lev[ch] = lev[v]+1, dfs(ch, v);
}

int lca(int a, int b){
	if(a == b) return a;
	if(lev[a] <lev[b]) std::swap(a, b);
	for(int l = 19; l >= 0; --l) if(lev[a] - (1<<l) >= lev[b]) a = par[l][a];
	if(a == b) return a;
	for(int l = 19; l >= 0; --l) if(par[l][a] != par[l][b]) a = par[l][a], b = par[l][b];
	return par[0][a];
}

int dist(int a, int b){
	int lc = lca(a, b);
	return lev[a] + lev[b] - 2*lev[lc];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	REP(l, 1, 20){
		FOR(i, n){
			if(par[l-1][i] == -1) par[l][i] = -1;
			else par[l][i] = par[l-1][par[l-1][i]];
		}
	}
	int q;
	std::cin >> q;
	while(q--){
		int x, y, a, b, k;
		std::cin >> x >> y >> a >>b >> k;
		x--;y--;a--;b--;
		if(dist(a, b) % 2 == k % 2 && dist(a, b) <= k) std::cout << "YES\n";
		else{
			int ds = dist(a, x)+dist(y, b)+1;
			if(ds % 2 == k%2 && ds <= k) std::cout << "YES\n";
			else{
				ds = dist(a, y)+dist(x, b)+1;
				if(ds%2 == k%2 && ds <= k) std::cout << "YES\n";
				else std::cout << "NO\n";
			}
		}
	}
	return 0;
}