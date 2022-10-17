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
	int q;
	std::cin >> q;
	while(q--){
		int n;
		std::cin >> n;
		if(n < 4) std::cout << -1 << "\n";
		else{
			if(n % 4 == 0 || n % 4 == 2) std::cout << n/4 << "\n";
			else if(n % 4 == 1){
				if(n == 5) std::cout << -1 << "\n";
				else std::cout << n/4-1 << "\n";
			}else{
				if(n == 7) std::cout << -1 << "\n";
				else if(n == 11) std::cout << -1 << "\n";
				else std::cout << n/4-1 << "\n";
			}
		}
	}
	return 0;
}