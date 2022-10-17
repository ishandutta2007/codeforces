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
		int n, k;
		std::cin >> n >> k;
		VI A(n), B(n);
		FOR(i, n) std::cin >> A[i];
		FOR(i, n) std::cin >> B[i];
		FOR(_, k){
			std::sort(A.begin(), A.end(), std::greater<int>());
			std::sort(B.begin(), B.end());
			if(A.back() < B.back()){
				std::swap(A.back(), B.back());
			}
		}
		int sum = 0;
		FOR(i, n) sum += A[i];
		std::cout << sum << "\n";
	}

	return 0;
}