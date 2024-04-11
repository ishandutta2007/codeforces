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

int n, m;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end(), std::greater<int>());
	REP(ans, 1, n+1){
		int wyn = 0;
		int cur = 0;
		int mins = 0;
		FOR(i, n){
			wyn += std::max(A[i]-mins, 0);
			cur++;
			if(cur == ans) mins++, cur = 0;
		}
		if(wyn >= m){
			std::cout << ans << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";
	return 0;
}