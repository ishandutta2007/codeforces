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
	int one = 1+2+3+4+5+6-7;
	while(t--){
		ll x;
		std::cin >> x;
		if(x < one) std::cout << "NO\n";
		else{
			x = x%one;
			if(x >= 1 && x <= 6) std::cout << "YES\n";
			else std::cout << "NO\n";
		}
	}
	return 0;
}