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
    VI A(n);
    FOR(i, n){
      char a;
      std::cin >> a;
      A[i] = a-'0';
    }
    VI B(n), C(n);
    B[0] = C[0] = 1;
    bool was = false;
    REP(i, 1, n){
      if(was){
        B[i] = 0;
        C[i] = A[i];
      }else{
        if(A[i] == 1){
          B[i] = 1;
          C[i] = 0;
          was = true;
        }else{
          B[i] = A[i]/2;
          C[i] = A[i]/2;
        }
      }
    }
    FOR(i, n) std::cout << B[i];
    std::cout << "\n";
    FOR(i, n) std::cout << C[i];
    std::cout << "\n";
  }

	return 0;
}