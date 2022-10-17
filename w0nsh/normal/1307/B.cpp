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
	int t;
	std::cin >> t;
	while(t--){
		int n, x;
		std::cin >> n >> x;
		VI A(n);
		int one = 0;
		FOR(i, n){
			std::cin >> A[i];
			if(A[i] == x) one = 1;
		}
		int mx = *std::max_element(A.begin(), A.end());
		if(one) std::cout << 1 << "\n";
		else{
			if(mx > x) std::cout << 2 << "\n";
			else{
				std::cout << x/mx + (x%mx == 0 ? 0 : 1) << "\n";
			}
		}
	}
	return 0;
}