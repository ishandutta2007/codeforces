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
    ll n, k;
    std::cin >> n >> k;
    k--;
    for(int i = n-1; i >= 1; --i){
      ll mam = (n-i);
      if(k < mam){
        std::string s;
        FOR(j, k) s.push_back('a');
        s.push_back('b');
        FOR(j, n-i-k-1) s.push_back('a');
        s.push_back('b');
        FOR(j, i-1) s.push_back('a');
        std::reverse(s.begin(), s.end());
        std::cout << s << "\n";
        break;
      }
      k -= mam;
    }
  }

	return 0;
}