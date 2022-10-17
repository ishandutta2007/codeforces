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

int n, m;
std::vector<VI> g;
std::vector<ll> A;
std::vector<ll> xr;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<ll> uid(0, (1ll<<62)-1ll);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		g = std::vector<VI>(n);
		xr.resize(n);
		A.resize(n);
		FOR(i, n) std::cin >> A[i], xr[i] = uid(rng);
		std::vector<ll> hash(n);
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			g[a].push_back(b);
			hash[b] ^= xr[a];
		}
		std::map<ll, ll> map;
		FOR(i, n) map[hash[i]] += A[i];
		ll ans = 0;
		TRAV(pr, map){
			if(pr.X == 0) continue;
			ans = std::gcd(ans, pr.Y);
		}
		std::cout << ans << "\n";
	}
	return 0;
}