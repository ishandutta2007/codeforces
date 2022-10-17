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

const int INF = 1000000666;

int n;
std::vector<VI> g;
VI parent;
std::vector<bool> block;
std::vector<std::map<int, int> > dists;
VI size;
VI ans;

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

void dfs(int v, int par, int lev, std::map<int, int> &map, int dude){
	map[v] = lev;
	if(ans[v] == 0) ans[dude] = std::min(ans[dude], lev);
	TRAV(ch, g[v]){
		if(ch == par || block[ch]) continue;
		dfs(ch, v, lev+1, map, dude);
	}
}

void rec(int v, int from=-1){
	int all = rozm(v);
	int cent = centroid(v, -1, all);
	parent[cent] = from;

	dfs(cent, -1, 0, dists[cent], cent);

	block[cent] = true;
	TRAV(ch, g[cent]){
		if(block[ch]) continue;
		rec(ch, cent);
	}
}

int closest(int v){
	int cur = v;
	int ret = INF;
	while(cur != -1){
		ret = std::min(ret, dists[cur][v] + ans[cur]);
		cur = parent[cur];
	}
	return ret;
}

void paint(int v){
	int cur = v;
	while(cur != -1){
		ans[cur] = std::min(ans[cur], dists[cur][v]);
		cur = parent[cur];
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int m;
	std::cin >> n >> m;
	g.resize(n);
	size.resize(n);
	dists.resize(n);
	ans.resize(n, INF);
	parent.resize(n, -1);
	ans[0] = 0;
	block.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rec(0);
	while(m--){
		int a, b;
		std::cin >> a >> b;
		b--;
		if(a == 1){
			paint(b);
		}else{
			std::cout << closest(b) << "\n";
		}
	}
	return 0;
}