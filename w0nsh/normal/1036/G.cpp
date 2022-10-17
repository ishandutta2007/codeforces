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

int n, m;
std::vector<VI> g;
VI src, snk, degin;
int rch[22];
std::vector<bool> rchvec;

void dfs(int v){
	rchvec[v] = true;
	TRAV(ch, g[v]) dfs(ch);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	degin.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		g[--a].push_back(--b);
		degin[b]++;
	}
	FOR(i, n){
		if(degin[i] == 0) src.push_back(i);
		if(SZ(g[i]) == 0) snk.push_back(i);
	}
	rchvec.resize(n);
	FOR(i, SZ(src)){
		dfs(src[i]);
		FOR(j, SZ(snk)) if(rchvec[snk[j]]) rch[i] |= 1<<j;
		std::fill(rchvec.begin(), rchvec.end(), false);
	}
	REP(i, 1, (1<<SZ(src))-1){
		int have = 0;
		int cur = i;
		int j = 0;
		while(cur > 0){
			if(cur&1) have |= rch[j]; 
			j++;
			cur >>= 1;
		}
		if(__builtin_popcount(i) >= __builtin_popcount(have)){
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
	return 0;
}