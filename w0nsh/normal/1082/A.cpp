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

int t;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> t;
	while(t--){
		int n, x, y, d;
		std::cin >> n >> x >> y >> d;
		if(x % d == y % d) std::cout << std::abs(y-x)/d << "\n";
		else{
			int min = 2000000666;
			if(y % d == 1) min = std::min(min, (x-1)/d + ((x-1)%d == 0 ? 0 : 1) + (y-1)/d);
			if(y % d == n % d) min = std::min(min, (n-x)/d + ((n-x)%d == 0 ? 0 : 1) + (n-y)/d);
			if(min == 2000000666) std::cout << -1 << "\n";
			else std::cout << min << "\n";
		}
	}
	return 0;
}