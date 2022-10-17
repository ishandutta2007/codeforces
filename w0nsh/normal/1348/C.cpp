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
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    std::reverse(s.begin(), s.end());
    std::vector<std::string> A(k);
    FOR(i, k) A[i].push_back(s.back()), s.pop_back();
    if(A[0] != A.back()){
      std::cout << A.back() << "\n";
      continue;
    }
    if(SZ(s) == 0 || s[0] == s.back()){
      int ind = 0;
      while(SZ(s)) A[ind].push_back(s.back()), s.pop_back(), ind = (ind+1)%k;
    }else{
      while(SZ(s)) A[0].push_back(s.back()), s.pop_back();
    }
    std::cout << A[0] << "\n";
  }

	return 0;
}