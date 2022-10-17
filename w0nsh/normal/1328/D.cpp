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
  int q;
  std::cin >> q;
  while(q--){
    int n;
    std::cin >> n;
    VI A(n);
    std::set<int> xd;
    FOR(i, n) std::cin >> A[i], xd.insert(A[i]);
    if(SZ(xd) == 1){
      std::cout <<1 << "\n";
      FOR(i, n) std::cout << 1 << " ";
      std::cout << "\n";
      continue;
    }
    if(n%2 == 0){
    std::cout <<2 << "\n";
      FOR(i, n) std::cout << i%2+1 << " ";
      std::cout << "\n";
      continue;
    }
    int pos = -1;
    FOR(i, n) if(A[i] == A[(i+1)%n]) pos = i;
    if(pos == -1){
      std::cout << 3 << "\n";
      std::cout << 3 << " ";
      FOR(i, n-1) std::cout << i%2+1 << " ";
      std::cout << "\n";
    }else{
      VI C(n);
      FOR(i, n){
        C[(i+pos+1)%n] = i%2+1;
      }
      std::cout << 2<< "\n";
      FOR(i, n) std::cout << C[i] << " ";
      std::cout << "\n";
    }
  }
	return 0;
}