#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
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

void solve(int tc) {
  int n;
  cin>>n;
  vi v(n);
  rep(i,0,n) cin>>v[i];

  map<int,int> best;
  vi ans(n);

  auto update = [&](int x, int a) {
    best[x] = max(best[x], a);
    auto it = best.lower_bound(x);
    while(next(it) != end(best) && it->second >= next(it)->second) {
      best.erase(next(it));
    }
  };


  vi nxt_ge(n);
  vector<pii> st;
  st.emplace_back(1e9,n);
  for(int i = n; i--;) {
    while(st.back().first <= v[i]) st.pop_back();
    nxt_ge[i] = st.back().second;
    st.emplace_back(v[i], i);
  }


  vector<vector<pii>> delayed(n+1);

  best[0] = 0;
  delayed[0].emplace_back(0,1);

  rep(i,0,n) {
    auto it = best.upper_bound(v[i]);
    assert(it != begin(best));
    --it;
    ans[i] = 1 + it->second;
    update(v[i], ans[i]);
    for(auto [x,a] : delayed[i]) update(x,a);
    delayed[nxt_ge[i]].emplace_back(v[i], ans[i]+1);
  }
  debug(ans);

  int mx = 0;
  rep(i,0,n) mx = max(mx,ans[i]);
  cout << mx << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}