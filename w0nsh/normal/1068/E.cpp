#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, k;
std::vector<VI> g;
VI par, lev;

void fail(){
	std::cout << "No\n";
	std::exit(0);
}

void dfs(int v){
	TRAV(ch, g[v]){
		if(par[v] == ch) continue;
		par[ch] = v;
		lev[ch] = lev[v]+1;
		dfs(ch);
	}
}

void dfs2(int v, int p, int l){
	if(SZ(g[v]) < 3){
		if(l != k || SZ(g[v]) == 2) fail();
	}else if(SZ(g[v]) == 3){
		if(p != -1) fail();
	}
	TRAV(ch, g[v]){
		if(ch != p) dfs2(ch, v, l+1);
	}	
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	lev.resize(n);
	par.resize(n, -1);
	dfs(0);
	int vert = 0;
	FOR(i, n) if(lev[vert] < lev[i]) vert = i;
	lev[vert] = 0;
	std::fill(par.begin(), par.end(), -1);
	dfs(vert);
	vert = 0;
	FOR(i, n) if(lev[vert] < lev[i]) vert = i;
	int dia = lev[vert];
	if(dia%2 != 0 || dia/2 != k) fail();
	FOR(i, dia/2) vert = par[vert];
	dfs2(vert, -1, 0);
	std::cout << "Yes\n";
	return 0;
}