#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif


template<class I>
I bs(I a, I b, auto&& f) {
  assert(a < b);
  while(a + 1 < b) { // floats: s/1/eps
    I q = a + (b - a)/2;
    (f(q) ? b : a) = q;
  }
  return b;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vi> a(n,vi(m));
  for(auto &y : a) for(auto &x : y) cin >> x;

  int M = 1<<m;
  int bestA = -1, bestB = -1;
  auto f = [&](int q){
      vi cnt(M);
      rep(i,0,n) {
        int msk = 0;
        rep(j,0,m) msk = 2*msk + (a[i][j] >= q ? 1 : 0);
        cnt[msk] = i+1;
      }
      rep(msk1,0,M) rep(msk2,0,M) if(cnt[msk1] && cnt[msk2]) {
        if((msk1 | msk2) == M-1) {
          bestA = cnt[msk1];
          bestB = cnt[msk2];
          return false;
        }
      }
      return true;
    };
  int ans = bs<int>(-1, 1e9+5, f);
  //cout << ans << endl;
  cout << bestA << " " << bestB << endl;
}