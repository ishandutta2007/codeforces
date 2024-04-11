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
	int n, m, ta, tb, k;
	std::cin >> n >> m >> ta >> tb >> k;
	VI A(n), B(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];
	if(k >= n || k >= m){
		std::cout << -1;
		return 0;
	}
	ll best = 0;
	FOR(il, k+1){
		int plc = std::lower_bound(B.begin(), B.end(), A[il]+ta) - B.begin();
		int left = k-il;
		plc += left;
		if(plc >= m){
			std::cout << -1;
			return 0;
		}
		best = std::max(best, 1ll*B[plc]+1ll*tb);
	}
	std::cout << best;

	return 0;
}