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
	int q;
	std::cin >> q;
	while(q--){
		int n, k;
		std::cin >> n >> k;
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		int min = *std::min_element(A.begin(), A.end());
		int max = *std::max_element(A.begin(), A.end());
		if(max-min > 2*k){
			std::cout << -1 << "\n";
		}else{
			std::cout << min+k << "\n";
		}
	}
	return 0;
}