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
int mn, mx;
std::vector<bool> vis;

void dfs(int v){
	vis[v] = true;
	mn = std::min(v, mn);
	mx = std::max(mx, v);
	TRAV(ch, g[v]){
		if(!vis[ch]) dfs(ch);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	g.resize(n);
	vis.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	std::vector<PII> prze;
	FOR(i, n){
		if(!vis[i]) {
			mn = 1000000000;
			mx = -1;
			dfs(i);
			prze.push_back(MP(mn, mx));
		}
	}
	std::sort(prze.begin(), prze.end());
	int ans = 0;
	int upto = -1;
	TRAV(p, prze){
		if(p.X < upto){
			ans++;
		}
		upto = std::max(upto, p.Y);
	}
	std::cout << ans;

	return 0;
}