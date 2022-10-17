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
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n){
			std::cin >> A[i];
		}
		bool good = false;
		FOR(i, n-1){
			if(std::abs(A[i]-A[i+1]) >= 2){
				good = true;
				std::cout << "YES\n";
				std::cout << i+1 << " " << i+2 << "\n";
				break;
			}
		}
		if(!good) std::cout << "NO\n";
	}
	return 0;
}