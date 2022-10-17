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
		int a, b;
		std::cin >> a >> b;
		if(a == b) std::cout << 0 << "\n";
		else if(a < b){
			if(a%2 == b%2) std::cout << 2 << "\n";
			else std::cout << 1 << "\n";
		}else{
			if(a%2 == b%2) std::cout << 1 << "\n";
			else std::cout <<2 << "\n";
		}
	}

	return 0;
}