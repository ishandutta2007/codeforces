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

int n, m;
std::vector<VI> g;

std::vector<bool> vis;
std::vector<PR<int, int> > dia;
// VI dia;


int ml;
VI level, parent;
void dfs(int v){
	vis[v] = true;
	if(level[v] > level[ml]) ml = v;
	TRAV(ch, g[v]){
		if(ch != parent[v]){
			parent[ch] = v;
			level[ch] = level[v]+1;
			dfs(ch);
		}
	}
}

int find_dia(int v, bool add){
	std::fill(parent.begin(), parent.end(), -1);
	std::fill(level.begin(), level.end(), 0);
	ml = v;
	dfs(v);
	std::fill(parent.begin(), parent.end(), -1);
	std::fill(level.begin(), level.end(), 0);
	dfs(ml);
	int sr = level[ml];
	while(level[ml] != sr/2) ml = parent[ml];
	if(add) dia.push_back(MP(sr, ml));
	return sr;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	parent.resize(n);
	level.resize(n);
	g.resize(n);
	vis.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i, n){
		if(!vis[i]){
			find_dia(i, true);
		}
	}
	std::sort(dia.begin(), dia.end());
	FOR(i, SZ(dia)-1){
		g[dia[i].Y].push_back(dia[SZ(dia)-1].Y);
		g[dia[SZ(dia)-1].Y].push_back(dia[i].Y);
	}
	std::cout << find_dia(0, false) << "\n";
	FOR(i, SZ(dia)-1){
		std::cout << dia[i].Y+1 << " " << dia[SZ(dia)-1].Y+1 << "\n";
	}
	return 0;
}