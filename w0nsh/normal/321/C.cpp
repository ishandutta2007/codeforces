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
std::vector<char> A;
std::vector<bool> block;
VI size;

int rozm(int v, int par=-1){
	int ret = 1;
	TRAV(ch, g[v]){
		if(block[ch] || ch == par) continue;
		ret += rozm(ch, v);
	}
	return ret;
}

int centroid(int v, int par, int all){
	bool ths = true;
	size[v] = 1;
	TRAV(ch, g[v]){
		if(block[ch] || ch == par) continue;
		int xd = centroid(ch, v, all);
		if(xd != -1) return xd;
		if(size[ch] > all/2) ths = false;
		size[v] += size[ch];
	}
	if(all-size[v] > all/2) ths = false;
	if(ths) return v;
	return -1;
}

void rec(int v, char let){
	if(let > 'Z'){
		std::cout << "Impossible!";
		std::exit(0);
	}
	int all = rozm(v);
	if(all == 1){
		A[v] = let;
		block[v] = true;
		return;
	}
	int cent = centroid(v, -1, all);
	A[cent] = let;
	block[cent] = true;
	TRAV(ch, g[cent]){
		if(block[ch]) continue;
		rec(ch, let+1);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	A.resize(n);
	size.resize(n);
	block.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rec(0, 'A');
	TRAV(i, A) std::cout << i << " ";
	return 0;
}