#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::pair<ll, ll> PLL;
typedef std::vector<int> VI;

int n;
std::vector<PII> A;
std::vector<VI> g;

PLL dfs(int v, int par=-1){
	ll mn = 0, mx = 0;
	TRAV(ch, g[v]) if(ch != par){
		auto pr = dfs(ch, v);
		mn += std::max(1ll * pr.X + std::abs(A[v].X - A[ch].X),
						1ll * pr.Y + std::abs(A[v].X - A[ch].Y));
		mx += std::max(1ll * pr.X + std::abs(A[v].Y - A[ch].X),
						1ll * pr.Y + std::abs(A[v].Y - A[ch].Y));
	} 
	return MP(mn, mx);
}

void solve(){
	std::cin >> n;
	A.resize(n);
	g = std::vector<VI>(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	auto xd = dfs(0);
	std::cout << std::max(xd.X, xd.Y) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	return 0;
}