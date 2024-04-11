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

VI col;
std::vector<VI> g;

void dfs(int v, int cl=1){
	col[v] = cl;
	TRAV(ch, g[v]){
		if(col[ch] == col[v]){
			std::cout << -1 << "\n";
			std::exit(0);
		}
		if(col[ch] == 0) dfs(ch, (cl == 1 ? 2 : 1));
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	g.resize(n);
	col.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	FOR(i, n) if(col[i] == 0) dfs(i);

	VI a1, a2;
	FOR(i, n) if(col[i] == 1) a1.push_back(i+1);
			else a2.push_back(i+1);

	std::cout << SZ(a1) << "\n";
	TRAV(i, a1) std::cout << i << " ";
	std::cout << "\n";

	std::cout << SZ(a2) << "\n";
	TRAV(i, a2) std::cout << i << " ";

	return 0;
}