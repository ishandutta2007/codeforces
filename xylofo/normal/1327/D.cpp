#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void solve(int tc) {
  debug()
  int n;
  cin >> n;
  vi p(n), c(n);
  rep(i,0,n) { cin>>p[i]; --p[i]; }
  rep(i,0,n) cin>>c[i];

  int ans = n;

  rep(i,0,n) if(c[i] != -1) {
    int j = i;
    vi q;
    do {
      q.emplace_back(c[j]);
      c[j] = -1;
      j = p[j];
    } while(i != j);
    debug(q);
    auto go = [&](int d) {
      if(d >= ans) return;
      rep(off,0,d) {
        bool ok = true;
        rep(i,0,sz(q)/d) if(q[off] != q[(off+i*d)%sz(q)]) { ok = false; break; }
        if(ok) { ans = d; return; }
      }
    };
    for(int x = 1; x*x <= sz(q); ++x) if(sz(q)%x == 0) {
      go(x);
      go(sz(q)/x);
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}