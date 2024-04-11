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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		ll n;
		std::cin >> n;
		if(n <= 3){
			std::cout << n << "\n";
			continue;
		}
		n--;
		int rest = n%3;
		n /= 3;

		int bit = 0;
		while(true){
			ll mam = 1ll<<bit;
			if(n >= mam){
				n -= mam;
				bit += 2;
				continue;
			}
			if(rest == 0){
				std::cout << (1ll<<bit)+n << "\n";
			}else{
				ll pier = (1ll<<bit)+n;
				ll dru = 2;
				//std::cout << "pier " << pier << " n " << n << std::endl;
				for(int b = bit; b > 0; b -= 2){
					dru <<= 2;
					int what = (n>>(b-2))%4;
					if(what == 0) dru += 0;
					else if(what == 1) dru += 2;
					else if(what == 2) dru += 3;
					else dru += 1;
				}
				if(rest == 1) std::cout << dru << "\n";
				else std::cout << (pier^dru) << "\n";
			}
			break;
		}
	}

	return 0;
}