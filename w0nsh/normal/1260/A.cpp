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
	int n;
	std::cin >> n;
	FOR(i, n){
		int c, s;
		std::cin >> c >> s;
		if(s <= c){
			std::cout << s << "\n";
			continue;
		}
		int left = c;
		int cost = 0;
		while(left > 0 && s > 0){
			int ile = s/left;
			cost += ile*ile;
			s -= ile;
			left--;
		}
		assert(s == 0);
		std::cout << cost << "\n";
	}
	return 0;
}