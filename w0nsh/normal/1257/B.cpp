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
	int x, y;
	std::cin >> x >> y;
		if(x == 1){
			if(y == 1) std::cout << "YES\n";
			else std::cout << "NO\n";
		}else if(x == 2 || x == 3){
			if(y <= 3) std::cout << "YES\n";
			else std::cout << "NO\n";
		}else{
			std::cout << "YES\n";
		}
	}
	return 0;
}