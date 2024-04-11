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

const ll INF = 1000000000ll*1000000000ll;
int n, k;
std::vector<ll> A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
  std::cin >> n >> k;
  A.resize(n);
  FOR(i, n) std::cin >> A[i];
  std::sort(A.begin(), A.end());
  std::vector<ll> P(n+1);
  REP(i, 1, n+1) P[i] = P[i-1]+A[i-1];
  auto sum = [&](int a, int b){
     if(a > b) return 0ll;
    return P[b+1]-P[a];
  };
  ll ans = INF;
  ll cur = 0;
  FOR(i, k){
    cur += A[k-1]-A[i];
  }
  ans = std::min(cur, ans);
  cur = 0;
  FOR(i, k){
    cur += A[n-1-i]-A[n-k];
  }
  ans = std::min(ans, cur);

  std::set<int> check;
  FOR(i, n) check.insert(A[i]-1), check.insert(A[i]), check.insert(A[i]+1);
  TRAV(x, check){
    auto beg = std::lower_bound(A.begin(), A.end(), x);
    auto end = std::upper_bound(A.begin(), A.end(), x);
    int mam = end-beg;
    if(mam >= k) ans = 0;
    else{
      int need = k-mam;
      int l = beg-A.begin();
      int r = A.end()-end;
      ll ladd = 1ll*l*(x-1) - sum(0, (int)(beg-A.begin())-1);
      ll radd =  sum(end-A.begin(), n-1) - 1ll*r*(x+1);
      ans = std::min(ans, ladd+radd+need);
      if(l >= need){
        ans = std::min(ans, ladd+need);
      }
      if(r >= need){
        ans = std::min(ans, radd+need);
      }
    }
  }
  std::cout << ans << "\n";
	return 0;
}