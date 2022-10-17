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

ll n, k;
std::vector<ll> dump;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	dump.push_back(0);
	ll pow = 1;
	while(dump.back() < 1000000000000000000ll) dump.push_back(dump.back() + pow), pow *= 4;
	// FOR(i, 10) std::cout << i << " : " << dump[i] << "\n";
	int tests;
	std::cin >> tests;
	while(tests--){
		std::cin >> n >> k;
		if(n == 1 && k == 1){
			std::cout << "YES 0" << "\n";
			continue;
		}
		if(n == 1){
			std::cout << "NO\n";
			continue;
		}
		if(n == 2 && k == 3){
			std::cout << "NO\n";
			continue;
		}
		if(n-1 >= SZ(dump)){
			std::cout << "YES " << n-1 << "\n";
			continue;
		}
		if(dump[n-1] >= k-1){
			std::cout << "YES " << n-1 << "\n";
			continue;
		}
		if(k > dump[n]){
			std::cout << "NO " << "\n";
			continue;
		}
		if(k == dump[n]){
			std::cout << "YES 0" << "\n";
			continue;
		}
		ll sz = n;
		ll cnt = 1;
		ll left = k;
		ll subd = 0;
		bool good = false;
		while(sz > 0){
			if(left - (2ll*cnt-1) < 0){
				break;
			}
			subd += 2ll*cnt-1;
			left -= 2ll*cnt-1; 
			sz--;
			cnt *= 2;
		}
			ll xd = dump[n]-subd;
			if(left > xd) std::cout << "NO\n";
			else std::cout << "YES " << sz << "\n";
	}
	return 0;
}