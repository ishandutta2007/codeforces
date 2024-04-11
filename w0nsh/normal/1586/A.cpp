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
		int sum = 0;
		FOR(i, n) std::cin >> A[i], sum += A[i];

		bool good = false;
		REP(i, 2, sum){
			if(sum % i == 0) good = true;
		}
		if(good){
			std::cout << n << "\n";
			FOR(i ,n) std::cout << i+1 << " ";
			std::cout << "\n";
		}else{
			std::cout << n-1 << "\n";
			FOR(i, n){
				if(A[i] % 2 == 1 && !good){
					good = true;
				}else{
					std::cout << i+1 << " ";
				}
			}
			std::cout << "\n";
		}


	}

	return 0;
}