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

int n;
std::vector<VI> g;
VI f;

int dfs(int v, int par=-1){
	if(v != 0 && SZ(g[v]) == 1) return 1;
	int sm = 10000000;
	if(f[v] == 0) sm = 0;
	TRAV(ch, g[v]){
		if(ch == par) continue;
		if(f[v] == 0) sm += dfs(ch, v);
		else sm = std::min(dfs(ch, v), sm);
	}
	return sm;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	f.resize(n);
	g.resize(n);
	FOR(i, n) std::cin >> f[i];
	FOR(i, n-1){
		int a;
		std::cin >> a;
		g[i+1].push_back(a-1);
		g[a-1].push_back(i+1);
	}
	int lf = 0;
	REP(i, 1, n) if(SZ(g[i]) == 1) lf++;
	std::cout << lf-dfs(0)+1;
	return 0;
}