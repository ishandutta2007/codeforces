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

int n, m;
VI pref, par, lev, pref_rev, right;
std::vector<VI> g;
std::vector<VI> tabs;
std::vector<std::vector<ll> > add_tabs; 
std::vector<ll> add, ans;

int _tick = 0;
void dfs0(int v){
	pref_rev[_tick] = v;
	pref[v] = _tick++;
	right[v] = pref[v];
	tabs[lev[v]].push_back(pref[v]);
	add_tabs[lev[v]].push_back(0);
	TRAV(ch, g[v]){
		if(ch == par[v]) continue;
		par[ch] = v;
		lev[ch] = lev[v]+1;
		dfs0(ch);
		right[v] = right[ch];
	}
}

void dfs1(int v, ll pls=0){
	pls += add[v];
	// std::cout << "subtree " << v+1 << " add " << add[v] << "\n";
	ans[v] = pls;
	TRAV(ch, g[v]) if(ch != par[v]) dfs1(ch, pls); 
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	pref.resize(n);
	par.resize(n);
	pref_rev.resize(n);
	lev.resize(n);
	tabs.resize(n+5);
	add_tabs.resize(n+5);
	right.resize(n);
	add.resize(n);
	ans.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	par[0] = -1;
	dfs0(0);
	std::cin >> m;
	while(m--){
		int v, d, x;
		std::cin >> v >> d >> x;
		v--;
		add[v] += x;
		if(SZ(g[v]) > 0){
			int level = lev[v] + d + 1;
			if(level > n+2) continue;
			int left = pref[v];
			int rgh = right[v];
			auto it = std::lower_bound(tabs[level].begin(), tabs[level].end(), left);
			auto jt = std::upper_bound(tabs[level].begin(), tabs[level].end(), rgh);
			if(it != tabs[level].end()) add_tabs[level][std::distance(tabs[level].begin(), it)] -= x;
			if(jt != tabs[level].end()) add_tabs[level][std::distance(tabs[level].begin(), jt)] += x;
			// if(it != tabs[level].end()) std::cout << "adding from " << pref_rev[*it]+1 << std::endl;
			// if(jt != tabs[level].end()) std::cout << " to " << pref_rev[*jt]+1 << std::endl;
		}
	}
	FOR(l, n){
		ll cur = 0;
		FOR(i, SZ(tabs[l])){
			cur += add_tabs[l][i];
			add[pref_rev[tabs[l][i]]] += cur;
			// std::cout << "adding " << cur << " to " << pref_rev[tabs[l][i]]+1 << "\n";
		}
	}
	dfs1(0);
	FOR(i, n) std::cout << ans[i] << " ";
	std::cout << "\n";
	return 0;
}