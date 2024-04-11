#pragma GCC optimize "O3"
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
typedef unsigned long long ull;

std::vector<std::vector<ull> > nums;
void rec(int kt, int upto, ull xr, std::map<ull, int> &map){
	if(kt == upto){
		map[xr]++;
		return;
	}
	TRAV(i, nums[kt]){
		rec(kt+1, upto, xr^i, map);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::srand(std::chrono::steady_clock::now().time_since_epoch().count());

	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<PII> > g(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(MP(c, b));
	}

	FOR(i, n) std::sort(g[i].begin(), g[i].end());
	std::vector<unsigned long long> L(n);
	FOR(i, n){
		L[i] = (1ll*std::rand()*std::rand() + std::rand() + std::rand()%30);
	}

	ull xr_all = 0;
	FOR(i, n) xr_all ^= L[i];


	std::vector<VI> hehe(k+1);
	nums.resize(k+1);
	FOR(i, n){
		hehe[SZ(g[i])].push_back(i);
	}

	REP(i, 1, k+1){
		FOR(j, i){
			ull xr = 0;
			TRAV(v, hehe[i]) xr ^= L[g[v][j].Y];
			nums[i].push_back(xr);
		}
	}

	std::map<ull, int> m1, m2;
	rec(1, std::min(k+1, 7), 0, m1);
	if(k <= 6){
		std::cout << m1[xr_all] << "\n";
		return 0;
	}
	rec(7, k+1, 0, m2);
	
	ll ans = 0;
	TRAV(pr, m1){
		ans += pr.Y*m2[xr_all^pr.X];
	}
	std::cout << ans << "\n";

	return 0;
}