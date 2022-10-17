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
int tab[100005][3];
ll dfs(int v, const VI &p, int kt=0, int par=-1){
	ll cost = tab[v][p[kt]];
	TRAV(ch, g[v]) if(ch != par) cost += dfs(ch, p, (kt+1)%3, v);
	return cost;
}
int xd[100005];
void show(int v, const VI &p, int kt=0, int par=-1){
	xd[v] = p[kt]+1;
	TRAV(ch, g[v]) if(ch != par) show(ch, p, (kt+1)%3, v);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	g.resize(n);
	FOR(j, 3){
		FOR(i, n){
		std::cin >> tab[i][j];
	}	
	}

	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int good = -1;
	FOR(i, n){
		if(SZ(g[i]) > 2){
			std::cout << -1 << "\n";
			return 0;
		}
		if(SZ(g[i]) == 1) good = i;
	}
	VI p;
	FOR(i, 3) p.push_back(i);
	ll ans = 1000000000ll*1000000000ll;
	VI best;
	do{
		ll cand= dfs(good, p);
		if(cand < ans){
			ans = cand;
			best = p;
		}
		ans = std::min(dfs(good, p), ans);
	}while(std::next_permutation(p.begin(), p.end()));
	std::cout << ans << "\n";
	show(good, best);
	FOR(i, n) std::cout << xd[i] << " ";
	return 0;
}