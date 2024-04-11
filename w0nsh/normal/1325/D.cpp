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

bool try2(ll x, ll s){
	ll ans1 = 0;
	ll ans2 = 0;
	bool need = false;
	for(int i = 61; i >= 0; --i){
		if((x & (1ll<<i)) != 0 && (s & (1ll<<i)) == 0){
			if(!need) return false;
			ans1 += (1ll<<i);
		}else
		if((x & (1ll<<i)) != 0 && (s & (1ll<<i)) != 0){
			if(need) return false;
			ans1 += (1ll<<i);
		}else
		if((x&(1ll<<i)) == 0 && (s & (1ll<<i)) != 0){
			assert(i != 0);
			if(need){
				ans1 += (1ll<<i);
				ans2 += (1ll<<i);
			}
			need = true;
		}else{
			if(need){
				ans1 += (1ll<<i);
				ans2 += (1ll<<i);
			}
			need = false;
		}
	}
	if(need) return false;
	assert((ans1^ans2) == x && ans1+ans2 == s);
	std::cout << 2 << "\n";
	std::cout << ans1 << " " << ans2 << "\n";
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	ll x, s;
	std::cin >> x >> s;
	if(x > s || (x%2 != s%2)){
		std::cout << -1;
		return 0;
	}
	if(x == 0 && s == 0){
		std::cout << 0 << "\n";
		return 0;
	}
	if(x == s){
		std::cout << 1 << "\n";
		std::cout << x << "\n";
		return 0;
	}
	if(!try2(x, s)){
		std::cout << 3 << "\n";
		std::cout << x << " " << (s-x)/2 << " " << (s-x)/2 << "\n";
	}
	return 0;
}