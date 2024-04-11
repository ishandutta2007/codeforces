#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

std::vector<VI> g;


PII dfs1(int v, int par=-1){
	PII my = MP(0, 0);
	if(SZ(g[v]) == 1) my.X = 1;
	TRAV(ch, g[v]) if(ch != par){
		auto xd = dfs1(ch, v);
		my.Y = std::max(my.Y, xd.X);
		my.X = std::max(my.X, xd.Y);
	}
	return my;
}

int ans;
PII dfs2(int v, int par=-1){
	PII my = MP(0, 0);
	TRAV(ch, g[v]) if(ch != par){
		auto xd = dfs2(ch, v);
		my.X += xd.X;
		my.Y += xd.Y;
	}
	ans += std::min(1, my.X) + my.Y;
	if(SZ(g[v]) == 1) return MP(1, 0);
	else return MP(0, 1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i, n) if(SZ(g[i]) != 1){
		auto xd = dfs1(i);
		if(xd.X && xd.Y) std::cout << 3 << " ";
		else std::cout << 1 << " ";
		dfs2(i);
		std::cout << ans;
		break;
	}
	

	return 0;
}