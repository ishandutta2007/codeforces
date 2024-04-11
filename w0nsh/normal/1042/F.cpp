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

int n, k, ans = 1;
std::vector<VI> g;

int dfs(int v, int parent){
	if(SZ(g[v]) == 1) return 0;
	VI d;
	TRAV(ch, g[v]) if(ch != parent) d.push_back(dfs(ch, v)+1);  
	std::sort(d.begin(), d.end());
	while(SZ(d) >= 2){
		if(d[SZ(d)-1]+d[SZ(d)-2] <= k) break;
		ans++;
		d.pop_back();
	}
	return d.back();
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	g.resize(n);
	FOR(i, n-1){
		int a,b;
		std::cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	FOR(i, n) if(SZ(g[i]) > 1){
		dfs(i, -1);
		break;
	}
	std::cout << ans << "\n";
	return 0;
}