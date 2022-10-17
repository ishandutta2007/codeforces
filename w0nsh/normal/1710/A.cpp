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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  while(t--){
    int n, m, k;
    std::cin >> n >> m >> k;
    VI A(k);
    FOR(i, k) std::cin >> A[i];

    bool good = false;
    FOR(_, 2){
      std::swap(n, m);

      ll have = 0;
      bool was_3 = false;
      TRAV(a, A){
        if(a / n >= 2) have += a / n;
        if(a / n >= 3) was_3 = true;
      }
      if(m % 2 == 1 && !was_3){
        continue;
      }
      if(have >= m){
        good = true;
        break;
      }
    }
    
    std::cout << (good ? "Yes\n" : "No\n");
  }


  return 0;
}