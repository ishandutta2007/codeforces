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
typedef std::vector<int> VI;

ll aryt(int a, int b){
	return 1ll * (a + b) * (b - a + 1) / 2;
}

int mx = 0;

void solve(ll n){
	bool good = false;
	REP(i, 2, n+2){
		ll xd = aryt(1, i);
		if((n - xd) >= 0 && (n - xd) % i == 0){
			mx = std::max(mx, i);
			std::cout << i << " ";
			good = true;
		}
	}
	if(good){
		std::cout << "\n";
		return;
	}
	assert(__builtin_popcountll(n) == 1);
	std::cout << -1 << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		ll n;
		std::cin >> n;
		if(__builtin_popcountll(n) != 1){
			ll ile = 1;
			ll x = n;
			while(x % 2 == 0){
				ile *= 2;
				x /= 2;
			}
			__int128 xd = ile*2;
			if(xd * (xd + 1) / 2 > n){
				std::cout << x << "\n";
			}else{
				std::cout << ile*2 << "\n";
			}
		}else{
			std::cout << -1 << "\n";
		}
	}
	// for(int i = 2; i <= 200; i += 2){
	// 	std::cout << std::bitset<10>(i).to_string() << " ";
	// 	std::cout << i << " ";
	// 	solve(i);
	// }

	// std::cout << "mx " << mx << std::endl;

	return 0;
}