#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

ll l, r, x, y;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> l >> r >> x >> y;
	if(y % x != 0){
		std::cout << 0 << "\n";
		return 0;
	}
	ll mul = y/x;
	VI dv;
	int ans = 0;
	for(int i = 1; i*i<=mul; i++){
		if(mul%i == 0){
			ll ac = 1ll*i*x;
			ll bc = 1ll*(mul/i)*x;
			if(ac >= l && ac <= r && bc >= l && bc <= r && std::__gcd(ac, bc) == x){
				if(ac == bc) ans++;
				else ans += 2;
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}