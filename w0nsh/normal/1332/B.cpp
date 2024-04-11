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
	std::vector<int> primes;
	REP(i, 2, 32){
		bool pr = true;
		REP(j, 2, i) if(i%j == 0) pr = false;
		if(pr) primes.push_back(i);
	}
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		VI C(n);
		std::set<int> cols;
		FOR(i, n){
			FOR(j, SZ(primes)){
				if(A[i]%primes[j] == 0) C[i] = j;
			}
		}
		FOR(i, n) cols.insert(C[i]);
		std::map<int, int> map;
		int ind = 0;
		TRAV(i, cols) map[i] = ind++;
		TRAV(i, C) i = map[i];
		std::cout << ind << "\n";
		FOR(i, n) std::cout << C[i]+1 << " ";
		std::cout << "\n";
	}

	return 0;
}