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
int n, m;
std::vector<bool> vis;
std::vector<int> lev;

void dfs(int v){
	vis[v] = true;
	TRAV(ch, g[v]){
		if(vis[ch]) continue;
		lev[ch] = lev[v]+1;
		dfs(ch);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		g = std::vector<VI>(n);
		vis = std::vector<bool>(n);
		lev = std::vector<int>(n);
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0);
		int ile[2];
		ile[0] = ile[1] = 0;
		FOR(i, n) ile[lev[i]%2]++;
		int good = 0;
		if(ile[0] > ile[1]) good = 1;
		std::cout << std::min(ile[0], ile[1]) << "\n";
		FOR(i, n) if(lev[i]%2 == good) std::cout << i+1 << " ";
		std::cout << "\n";
	}
	return 0;
}