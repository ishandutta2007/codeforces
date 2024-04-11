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

int n;
VI sub;
std::vector<VI> g;
VI ans;

void dfs(int v, int par=-1){
	sub[v] = 0;
	if(SZ(g[v]) == 1 && par != -1) sub[v] = 1;
	TRAV(ch, g[v]){
		if(ch == par) continue;
		dfs(ch, v);
		sub[v] += sub[ch];
	}
	ans[sub[v]]++;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	if(n == 1){
		std::cout << "1" << "\n";
		return 0;
	}
	ans.resize(n+2);
	g.resize(n);
	sub.resize(n);
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		g[a].push_back(i+1);
		g[i+1].push_back(a);
	}
	dfs(0);
	int cur = 1;
	auto it = ans.begin();
	it++;
	FOR(i, n){
		while(*it == 0){
			cur++;
			it++;
		}
		(*it)--;
		std::cout << cur << " ";
	}
	return 0;
}