#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

std::vector<VI> g;
int dist(int v, int end, int par=-1){
	if(v == end) return 0;
	TRAV(ch, g[v]) if(ch != par){
		int cur = dist(ch, end, v);
		if(cur != -1) return cur+1;
	}
	return -1;
}

PII naj(int v, int par=-1){
	PII best = MP(0, v);
	TRAV(ch, g[v]) if(ch != par){
		auto his = naj(ch, v);
		his.X++;
		best = std::max(best, his);
	}
	return best;
}

void solve(){
	int n, a, b, da, db;
	std::cin >> n >> a >> b >> da >> db;
	g = std::vector<VI>(n);
	a--;b--;
	FOR(i, n-1){
		int x, y;
		std::cin >> x >> y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	int heh = dist(a, b, -1);
	int xd = naj(0).Y;
	int ds = naj(xd).X;

	bool fail = false;
	if(heh <= da) fail = true;
	if(2*da >= db) fail = true;
	if(2*da >= ds) fail = true;
	std::cout << (fail ? "Alice\n" : "Bob\n");
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	return 0;
}