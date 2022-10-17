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
		VI A, B;
		FOR(i, n){
			int a;
			std::cin >> a;
			if(a%2 == 0) A.push_back(a);
			else B.push_back(a);
		}
		std::sort(A.begin(), A.end());
		std::sort(B.begin(), B.end());
		ll ret = 0;
		FOR(i, n){
			if(i%2 == 0){
				if(SZ(A) == 0) B.pop_back();
				else if(SZ(B) != 0 && B.back() > A.back()) B.pop_back();
				else{
					ret += A.back();
					A.pop_back();
				}
			}else{
				if(SZ(B) == 0) A.pop_back();
				else if(SZ(A) != 0 && A.back() > B.back()) A.pop_back();
				else{
					ret -= B.back();
					B.pop_back();
				}
			}
		}
		if(ret == 0) std::cout << "Tie\n";
		else if(ret > 0) std::cout << "Alice\n";
		else std::cout << "Bob\n";
	}

	return 0;
}