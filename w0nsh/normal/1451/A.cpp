#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
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
		int ans = 0;
		if(n == 1) std::cout << 0 << "\n";
		else if(n == 2) std::cout << 1 << "\n";
		else if(n == 3) std::cout << 2 << "\n";
		else if(n%2 == 0) std::cout << 2 << "\n";
		else std::cout << 3 << "\n";
	}
	return 0;
}