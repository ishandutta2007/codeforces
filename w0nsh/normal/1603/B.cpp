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


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int x, y;
		std::cin >> x >> y;
		if(x == y){
			std::cout << x << "\n";
		}else if(x > y){
			std::cout << x+y << "\n";
		}else{
			int ile = (y-1)%x;
			assert(ile % 2 == 1);
			std::cout << y - 1 - (ile-1)/2 << "\n";
		}
	}

	return 0;
}