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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, x;
		std::cin >> n >> x;
		VI A(n);
		int sum = 0;
		FOR(i, n) std::cin >> A[i], sum += A[i];
		if(sum == x){
			std::cout << "NO\n";
		}else{
			sum = 0;
			FOR(i, n){
				sum += A[i];
				if(sum == x){
					std::swap(A[i], A[i+1]);
					break;
				}
			}
			std::cout << "YES\n";
			FOR(i, n) std::cout << A[i] << " ";
			std::cout << "\n";
		}
	}

	return 0;
}