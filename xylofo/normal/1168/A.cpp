#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


// finds lowest x in (a,b] such that f(x) = 1
// assumes f(a) = 0, f(b) = 0.
template<class I, class F>
I bs(I a, I b, F f) {
  assert(a < b);
  while(a + 1 != b) {
    I q = a + (b - a)/2;
    (f(q) ? b : a) = q;
  }
  return b;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  vi v(n);
  rep(i,0,n) cin>>v[i];
  int ans = bs(-1, m, [&](int q) {
    int low = 0;
    rep(i,0,n) {
      auto ok = [&](int a) {return a >= v[i] && a <= v[i]+q; };
      while(low < m && !ok(low) && !ok(low+m)) low++;
    }
    return low < m;
  });
  cout << ans << endl;
}