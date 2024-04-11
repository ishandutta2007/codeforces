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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		ll n, x;
		std::cin >> n >> x;
		std::string a;
		std::cin >> a;
		std::map<ll, int> map;
		int have = 0;
		FOR(i, n){
			have += (a[i] == '0' ? 1 : -1);
			map[have]++;
		}
		if(have == 0){
			if(map[x] == 0) std::cout << 0 << "\n";
			else std::cout << -1 << "\n";
			continue;
		}
		int add = have;
		ll ans = 0;
		TRAV(pr, map){
			if(std::abs(pr.X-x)%add == 0 && (add > 0 ? x >= pr.X : x <= pr.X)) ans += pr.Y;
		}
		if(x == 0) ans++;
		std::cout << ans << "\n";
	}
	return 0;
}