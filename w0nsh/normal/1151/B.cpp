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
	int n, m;
	std::cin >> n >> m;
	int row = -1;
	VI good;
	int xr = 0;
	FOR(i, n){
		int last;
		std::cin >> last;
		if(row == -1) good.clear();
		if(row == -1) good.push_back(last);
		bool ok = false;
		FOR(j, m-1){
			int a;
			std::cin >> a;
			if(a != last) ok = true; 
			if(row == -1) good.push_back(a);
		}
		if(ok && row == -1) row = i;
		else xr ^= last;
	}
	if(row == -1 && xr == 0) std::cout << "NIE\n";
	else{
		std::cout << "TAK\n";
		FOR(i, n){
			if(i != row) std::cout << 1 << " ";
			else{
				FOR(j, m) if((good[j] ^ xr )!= 0){
					std::cout << j+1 << " ";
					break;
				}
			}
		}
	}
	return 0;
}