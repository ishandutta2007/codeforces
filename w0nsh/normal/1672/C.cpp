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
		int first = -1;
		int last = -1;
		FOR(i, n-1){
			if(A[i] == A[i+1]){
				if(first == -1) first = i;
				last = i+1;
			}
		}

		if(last - first + 1 <= 2) std::cout << 0 << "\n";
		else{
			std::cout << (last - first + 1 == 3 ? 1 : last - first + 1 - 3) << "\n";
		}
	}

	return 0;
}