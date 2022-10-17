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
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	if(k == 1){
		std::cout << *std::min_element(A.begin(), A.end()) << "\n";
		return 0;
	}
	if(k > 2){
		std::cout << *std::max_element(A.begin(), A.end()) << "\n";
		return 0; 
	}
	int min = 1000000002;
	int best = -1000000002;
	TRAV(i, A){
		min = std::min(min, i);
		best = std::max(best, min);
	}
	min = 1000000002;
	for(int i = n-1; i >= 0; --i){
		min = std::min(min, A[i]);
		best = std::max(best, min);
	}
	std::cout << best << "\n";
	return 0;
}