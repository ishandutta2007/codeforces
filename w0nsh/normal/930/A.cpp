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

int n, cnt;
VI level;
std::vector<VI> g;

void dfs(int v, int par, int lev){
	level[lev]++;
	TRAV(ch, g[v]) if(ch != par) dfs(ch, v, lev+1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	level.resize(n);
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		g[i+1].push_back(a);
		g[a].push_back(i+1);
	}
	dfs(0, -1, 0);
	FOR(i, n) if(level[i]%2 == 1) cnt++;
	std::cout << cnt;
	return 0;
}