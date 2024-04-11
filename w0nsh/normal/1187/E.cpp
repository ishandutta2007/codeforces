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

int n, root;
std::vector<VI> g;


ll sz[200005], ws[200005], zg[200005];

void szdfs(int v, int par=-1){
	sz[v] = 1;
	TRAV(ch, g[v]) if(ch != par){
		szdfs(ch, v);
		sz[v] += sz[ch];
	}
}

void dfs(int v, int par=-1){
	if(SZ(g[v]) == 1){
		ws[v] = n;
		zg[v] = 1;
		return;
	}
	ll allzg = 0;
	TRAV(ch, g[v]) if(ch != par){
		dfs(ch, v);
		allzg += zg[ch];
	}
	TRAV(ch, g[v]) if(ch != par){
		ws[v] = std::max(ws[v], ws[ch]+n-sz[ch]+allzg-zg[ch]);
	}
	zg[v] = allzg+sz[v];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	if(n == 2){
		std::cout << 3 << "\n";
		return 0;
	}
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i, n) if(SZ(g[i]) > 1) root = i;
	szdfs(root);
	dfs(root);
	std::cout << ws[root] << "\n";
	return 0;
}