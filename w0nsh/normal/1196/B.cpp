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
		FOR(i, n) std::cin >> A[i], A[i] = A[i]%2;
		int ones = 0;
		FOR(i, n) if(A[i] == 1) ones++;
		if(ones < k || (ones-k+1)%2 == 0) std::cout << "NO\n";
		else{
			int take = ones-k;
			VI przedz;
			FOR(i, n){
				if(A[i] == 1){
					if(take <= 0) przedz.push_back(i);
					take--;
				}
			}
			std::cout << "YES\n";
			FOR(i, k-1){
				std::cout << przedz[i]+1 << " ";
			}
			std::cout << n << "\n";
		}
	}
	return 0;
}