#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
 
int n, m;
VI col;
std::vector<VI> g;

void dfs(int v, int c, int par=-1){
	TRAV(ch, g[v]) if(ch != par){
		if(col[ch] != -1){
			if(col[ch] == c) c = 0;
		}
	}
	col[v] = c;
	TRAV(ch, g[v]) if(ch != par){
		if(col[ch] == -1) dfs(ch, 1-c, v);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		col = std::vector<int>(n, -1);
		g = std::vector<VI>(n);
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0, 1);
		bool bad = false;
		FOR(i, n) if(col[i] == -1){
			bad = true;
		}
		if(bad) std::cout << "NO\n";
		else{
			std::cout << "YES\n";
			int cnt = 0;
			FOR(i, n) cnt += col[i];
			std::cout << cnt << "\n";
			FOR(i, n) if(col[i]) std::cout << i+1 << " ";
			std::cout << "\n";
		}
	}

	return 0;
}