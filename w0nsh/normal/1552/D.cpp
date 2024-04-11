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
		FOR(i, n) std::cin >> A[i];

		bool good = false;
		REP(mask, 1, 1<<n){
			int ile = __builtin_popcount(mask);
			FOR(m2, 1<<ile){
				int ind = 0;
				int sm = 0;
				FOR(i, n){
					if(mask & (1<<i)){
						if(m2 & (1<<ind)){
							sm += A[i];
						}else{
							sm -= A[i];
						}
						ind++;
					}
				}
				if(sm == 0) good = true;
			}
			if(good) break;
		}

		if(good) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}