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
    int n;
    std::cin >> n;
    n--;
    VI A;
    int have = 1;
    while(n > 0){
      if(n <= 2*have){
        A.push_back(n-have);
        break;
      }
      int bnd = n/2;
      int add = std::min(bnd-have, have);
      A.push_back(add);
      have += add;
      n -= have;
    }
    std::cout << SZ(A) << "\n";
    TRAV(i, A) std::cout << i << " ";
    std::cout << "\n";
  }

	return 0;
}