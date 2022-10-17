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

int n, cnt[3], ans;
int col[300005];

std::vector<VI> g;

PII dfs(int v, int par){
	PII ret = MP(0, 0);
	TRAV(ch, g[v]){
		if(ch == par) continue;
		auto xd = dfs(ch, v);
		if(xd.X == cnt[1] && xd.Y == 0) ans++;
		else if(xd.Y == cnt[2] && xd.X == 0) ans++;
		ret.X += xd.X;
		ret.Y += xd.Y;
	}
	if(col[v] == 1) ret.X++;
	if(col[v] == 2) ret.Y++;
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	FOR(i, n) std::cin >> col[i];
	FOR(i, n) cnt[col[i]]++;
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);
	std::cout << ans;
	return 0;
}