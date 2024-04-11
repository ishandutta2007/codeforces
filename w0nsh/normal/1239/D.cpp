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

std::vector<bool> vis;
std::vector<VI> g, grev;
int n;
VI topo;
void dfs(int v){
	vis[v] = true;
	TRAV(ch, g[v]){
		if(!vis[ch]) dfs(ch);
	}
	topo.push_back(v);
}
VI comp;
int cpn;
void dfsrev(int v){
	vis[v] = true;
	comp[v] = cpn;
	TRAV(ch, grev[v]){
		if(!vis[ch]) dfsrev(ch);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int m;
		std::cin >> n >> m;
		g =grev= std::vector<VI>(n);
		vis = std::vector<bool>(n);
		topo = VI();
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			g[a].push_back(b);
			grev[b].push_back(a);
		}
		if(n == 1){
			std::cout << "No\n";
			continue;
		}
		FOR(i, n) if(!vis[i]) dfs(i);
		std::reverse(topo.begin(), topo.end());
		cpn = 0;
		comp = VI(n, -1);
		vis = std::vector<bool>(n);
		TRAV(i, topo) if(!vis[i]) dfsrev(i), cpn++;
		if(cpn == 1) std::cout << "No\n";
		else{
			std::cout << "Yes\n";
			int jur = 0;
			FOR(i, n) if(comp[i] == cpn-1) jur++;
			std::cout << jur << " " << n-jur << "\n";
			FOR(i, n) if(comp[i] == cpn-1) std::cout << i+1 << " ";
			std::cout << "\n";
			FOR(i, n) if(comp[i] != cpn-1) std::cout << i+1 << " ";
			std::cout << "\n";
		}
	}
	return 0;
}