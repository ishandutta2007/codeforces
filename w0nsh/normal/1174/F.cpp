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


int dist(int v){
	v++;
	std::cout << "d " << v << std::endl;
	int a;
	std::cin >> a;
	return a;
}
int nast(int v){
	v++;
	std::cout << "s " << v << std::endl;
	int a;
	std::cin >> a;
	a--;
	return a;
}
int ans(int v){
	v++;
	std::cout << "! " << v << std::endl;
	std::exit(0);
}

int n;
std::vector<VI> g;
VI lev, par, sz;
int LEV;

void dfs(int v){
	if(lev[v] == LEV){
		sz[v] = 1;
		return;
	}
	sz[v] = 1;
	TRAV(ch, g[v]){
		if(ch == par[v]) continue;
		par[ch] = v;
		lev[ch] = lev[v]+1;
		dfs(ch);
		sz[v] += sz[ch];
	}
}

int CENT;
void sprawdz(int v, int all){
	if(sz[v] == 0) return;
	bool is_cent = (all-sz[v] <= all/2);
	TRAV(ch, g[v]){
		if(ch == par[v]) continue;
		sprawdz(ch, all);
		if(sz[ch] > all/2) is_cent = false;
	}
	if(is_cent) CENT = v;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	par.resize(n, -1);
	lev.resize(n);
	sz.resize(n);
	LEV = dist(0);
	if(LEV == 0) ans(0);
	dfs(0);
	int cur = 0;
	while(true){
		CENT = -1;
		sprawdz(cur, sz[cur]);
		assert(CENT != -1);
		if(CENT == cur){
			cur = nast(cur);
		}else{
			int dst = dist(CENT);
			if(dst == LEV-lev[CENT]){
				cur = CENT;
			}else{
				int xd = CENT;
				while(par[xd] != -1){
					xd = par[xd];
					sz[xd] -= sz[CENT];
				}
				sz[CENT] = 0;
			}
		}
		if(lev[cur] == LEV) ans(cur);
	}
	return 0;
}