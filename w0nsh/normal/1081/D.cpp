#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, m, k;
std::vector<bool> spec, vis;
std::vector<std::vector<PII> > g;

int can, rest;

void dfs(int v){
	vis[v] = true;
	if(spec[v]) can++;
	TRAV(ch, g[v]){
		if(ch.Y <= rest && !vis[ch.X]) dfs(ch.X);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	spec.resize(n);
	g.resize(n);
	int first_spec;
	FOR(i, k){
		int a;
		std::cin >> a;
		a--;
		spec[a] = true;
		first_spec = a;
	}
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(MP(b, c));
		g[b].push_back(MP(a, c));
	}
	int left = 1;
	int right = 1000000001;
	vis.resize(n);
	while(left < right){
		int mid = (left+right)/2;
		can = 0;
		rest = mid;
		std::fill(vis.begin(), vis.end(), false);
		dfs(first_spec);
		if(can == k) right = mid;
		else left = mid+1;
	}
	FOR(i, k) std::cout << left << " ";
	return 0;
}