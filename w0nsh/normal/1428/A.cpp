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
		PII a, b;
		std::cin >> a.X >> a.Y >> b.X >> b.Y;
		if(a == b) std::cout << 0 << "\n";
		else if(a.X == b.X || a.Y == b.Y){
			int roz = std::max(std::abs(a.X-b.X), std::abs(a.Y-b.Y));
			std::cout << roz << "\n";
		}else{
			std::cout << std::abs(a.X-b.X) + std::abs(a.Y-b.Y) + 2 << "\n";
		}
	}

	return 0;
}