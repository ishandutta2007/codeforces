#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
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
		int sum = 0;
		FOR(i, n) std::cin >> A[i], sum += A[i];
		if(sum%2 != 0){
			std::cout << "NO\n";
		}else{
			std::sort(A.begin(), A.end());
			std::reverse(A.begin(), A.end());
			int need = sum/2;
			TRAV(i, A) if(i <= need) need -= i;
			if(need == 0) std::cout << "YES\n";
			else std::cout << "NO\n";
		}
	}

	return 0;
}