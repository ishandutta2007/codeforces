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
		VI A(n);
		int xr = 0;
		FOR(i, n) std::cin >> A[i];
		TRAV(i, A) xr ^= i;
		if(xr == 0){
			std::cout << "DRAW\n";
		}else{
			int bt = -1;
			for(int i = 30; i >= 0; --i){
				if(xr & (1<<i)){
					bt = i;
					break;
				}
			}
			assert(bt != -1);
	

			int cnt = 0;
			TRAV(i, A) if(i & (1<<bt)) cnt++;
			if(n % 2 == 0){
				std::cout << "WIN\n";
			}else{
				if((cnt+1)%4 == 0) std::cout << "LOSE\n";
				else std::cout << "WIN\n";
			}
		}
	}

	return 0;
}