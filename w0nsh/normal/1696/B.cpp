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
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n){
			std::cin >> A[i];
		}
		if(*std::max_element(A.begin(), A.end()) == 0) std::cout << 0 << "\n";
		else{
			bool was = false;
			bool block = false;
			bool good = true;
			FOR(i, n){
				if(A[i] != 0){
					was = true;
					if(block){
						good = false;
						break;
					}
				}else{
					if(was){
						block = true;
					}
				}
			}
			if(good) std::cout << 1 << "\n";
			else std::cout << 2 << "\n";
		}
	}

	return 0;
}