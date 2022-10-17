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
		FOR(i, n) std::cin >> A[i];
		std::map<int, int> last;
		int best = -1;
		FOR(i, n){
			if(last.count(A[i])){
				if(best == -1) best = i-last[A[i]]+1;
				else best = std::min(best, i-last[A[i]]+1);
			}
			last[A[i]] = i;
		}
		std::cout << best << "\n";
	}
	return 0;
}