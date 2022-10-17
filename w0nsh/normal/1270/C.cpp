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
		int n;
		std::cin >> n;
		ll sum = 0;
		ll xr = 0;
		FOR(i, n){
			ll a;
			std::cin >> a;
			sum += a;
			xr ^= a;
		}
		std::vector<ll> ans;
		ll first = (1ll<<51) + xr;
		ans.push_back(first);
		sum += first;
		xr ^= first;
		ll need = 2ll*xr-sum;
		ans.push_back(need/2ll);
		ans.push_back(need/2ll);
		sum += need;
		assert(sum == 2ll*xr);
		std::cout << 3 << "\n";
		TRAV(i, ans) std::cout << i << " ";
		std::cout << "\n";
	}
	return 0;
}