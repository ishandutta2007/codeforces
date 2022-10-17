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
		int r, b, k;
		std::cin >> r >> b >> k;
		if(r == b) std::cout << "OBEY\n";
		else{
			if(r > b) std::swap(r, b);
			int gc = std::__gcd(r, b);
			b /= gc;
			r /= gc;
			if((b-2)/r >= k-1) std::cout << "REBEL\n";
			else std::cout << "OBEY\n";
		}
	}
	return 0;
}