#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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
    int n, k;
    std::cin >> n >> k;
    VI A(n);
    FOR(i, n) std::cin >> A[i];
    std::set<int> have;
    FOR(i,n) have.insert(A[i]);
    if(SZ(have) > k){
      std::cout << -1 << "\n";
      continue;
    }
    VI rep;
    TRAV(i, have) rep.push_back(i);
    while(SZ(rep) < k) rep.push_back(*have.begin());
    std::cout << 100*SZ(rep) << "\n";
    FOR(i, 100){
      TRAV(j, rep) std::cout << j << " ";
    }
    std::cout << "\n";
  }

	return 0;
}