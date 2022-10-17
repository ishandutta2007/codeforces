#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

std::vector<VI> g;
std::vector<int> vec;
bool dfs(int v, int par){
	int ile = 0;
	bool leaf = true;
	TRAV(ch, g[v]) if(ch != par) {
		if(dfs(ch, v)){
			leaf = false;
			ile++;
		}
	}

	if(leaf) {
		return true;
	}

	vec.push_back(ile);
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		g = std::vector<VI>(n);
		vec = VI();
		FOR(i, n-1){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0, -1);
		int sm = 0;
		TRAV(i, vec) sm += i-1;
		sm++;
		std::cout << sm << "\n";
		
	}

	return 0;
}