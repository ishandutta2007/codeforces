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

int n;
std::vector<VI> g;

VI ans, sub, dist;
std::vector<bool> chip;



namespace centro{

std::vector<bool> block;

int CENT, SZ;
int szdfs(int v, int par=-1){
	bool good = true;
	int sz = 1;
	TRAV(ch, g[v]) if(ch != par && !block[ch]){
		int his = szdfs(ch, v);
		if(his*2 > SZ) good = false;
		sz += his;
	}
	if((SZ-sz)*2 > SZ) good = false;
	if(good) CENT = v;
	return sz;
}

void init(){
	block.resize(n);
}

void dfs(int v, VI& vec, int dst=0, int par=-1){
	int co = std::min(dist[v]-dst-1, SZ(vec)-1);
	if(co >= 0){
		vec[co] = std::max(vec[co], dist[v]);
	}
	TRAV(ch, g[v]) if(ch != par && !block[ch]){
		dfs(ch, vec, dst+1, v);
	}
}

void dfs2(int v, VI& vec, int dst=0, int par=-1){
	ans[v] = std::max(ans[v], vec[dst]);
	TRAV(ch, g[v]) if(ch != par && !block[ch]){
		dfs2(ch, vec, dst+1, v);
	}
}

void rec(int v){
	CENT = -1;
	SZ = szdfs(v); szdfs(v);
	assert(CENT != -1);
	v = CENT;
	block[v] = true;

	VI ile(SZ);
	dfs(v, ile);
	for(int i = SZ-2; i >= 0; --i) ile[i] = std::max(ile[i], ile[i+1]);
	dfs2(v, ile);
	TRAV(ch, g[v]) if(!block[ch]) rec(ch);
}

}

int dfs(int v, int par=-1){
	sub[v] = 1000000000;
	TRAV(ch, g[v]){
		if(par != ch){
			sub[v] = std::min(sub[v], dfs(ch, v)+1);
		}
	}
	if(chip[v]) sub[v] = 0;
	return sub[v];
}

void dfs2(int v, int up=1000000000, int par=-1){
	dist[v] = std::min(up, sub[v]);
	TRAV(ch, g[v]){
		if(par != ch){
			dist[v] = std::min(dist[v], sub[v]);
		}
	}
	TRAV(ch, g[v]){
		if(par != ch){
			dfs2(ch, dist[v]+1, v);
		}
	}
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

	int k;
	std::cin >> k;
	sub.resize(n);
	dist.resize(n);
	chip.resize(n);
	FOR(i, k){
		int a;
		std::cin >> a;
		chip[--a] = true;
	}
	dfs(0);
	dfs2(0);

	ans.resize(n);

	centro::init();
	centro::rec(0);

	FOR(i, n) std::cout << ans[i] << " ";
	std::cout << "\n";

	return 0;
}