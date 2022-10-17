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
		int n;
		std::cin >> n;
		std::map<int, int> map;
		FOR(i, n){
			int a;
			std::cin >> a;
			map[a]++;
		}
		int mx = 0;
		TRAV(i, map) mx = std::max(mx, i.Y);
		int mam = SZ(map);
		if(mam == mx) std::cout << mx-1 << "\n";
		else std::cout << std::min(mam, mx) << "\n";
	}

	return 0;
}