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

ll ans;
int n;
std::vector<VI> g;
std::vector<bool> block;
VI A;
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

void dfs(int v, int par, int xr, std::vector<PII> &ile){
	xr ^= A[v];
	ans += 2ll*xr;
	FOR(i, 20){
		if(xr & (1<<i)) ile[i].X++;
		else ile[i].Y++;
	}
	TRAV(ch, g[v]){
		if(block[ch] || ch == par) continue;
		dfs(ch, v, xr, ile);
	}
}

void rec(int v){
	int all = rozm(v);
	int cent = centroid(v, -1, all);


	ans += 2ll*A[cent];

	std::vector<PII> ile(20);
	std::map<int, std::vector<PII> > map;
	TRAV(ch, g[cent]){
		if(block[ch]) continue;
		map[ch] = std::vector<PII>(20);
		dfs(ch, cent, A[cent], map[ch]);
		FOR(i, 20) ile[i].X += map[ch][i].X, ile[i].Y += map[ch][i].Y;  
	}
	TRAV(ch, g[cent]){
		if(block[ch]) continue;
		FOR(i, 20) ile[i].X -= map[ch][i].X, ile[i].Y -= map[ch][i].Y;  
		FOR(i, 20){
			ll same = 1ll*ile[i].X*map[ch][i].X + 1ll*ile[i].Y*map[ch][i].Y;
			ll inne = 1ll*ile[i].X*map[ch][i].Y + 1ll*ile[i].Y*map[ch][i].X;
			if(A[cent] & (1<<i)) ans += (1ll<<i)*same;
			else ans += (1ll<<i)*inne; 
		}
		FOR(i, 20) ile[i].X += map[ch][i].X, ile[i].Y += map[ch][i].Y;  
	}
	
	block[cent] = true;
	TRAV(ch, g[cent]){
		if(block[ch]) continue;
		rec(ch);
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
	FOR(i, n) std::cin >> A[i];
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rec(0);
	std::cout << ans/2ll;
	return 0;
}