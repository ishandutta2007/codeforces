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

void first() { cout << "tokitsukaze" << endl; exit(0); }
void second() { cout << "quailty" << endl; exit(0); }
void draw() { cout << "once again" << endl; exit(0); }

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin>>n>>k;
  string s;
  cin>>s;
  vi l(2,n), r(2,-1);
  rep(i,0,n) {
    int c = s[i]-'0';
    l[c] = min(l[c],i);
    r[c] = max(r[c],i);
  }
  debug(l,r);

  rep(c,0,2) if(r[c]-l[c]+1 <= k) first();

  const int undef = -10000;
  rep(q,0,2) {
    vi ls(n, undef), rs(n,undef);
    rep(i,0,n) {
      int c = s[i]-'0';
      if(i) ls[i] = ls[i-1];
      if(c == q) ls[i] = i;
    }
    for(int i = n-1; i >= 0; --i) {
      int c = s[i]-'0';
      if(i+1<n) rs[i] = rs[i+1];
      if(c == q) rs[i] = i;
    }
    debug(q, ls, rs);
    rep(i,0,n-k+1) {
      int lk = i ? ls[i-1] : undef;
      int rk = (i+k<n) ? rs[i+k] : undef;
      debug(i,lk,rk);
      if(lk != undef && rk != undef) draw();
      if(lk != undef && abs(lk-l[q])+1 > k) draw();
      if(rk != undef && abs(r[q]-rk)+1 > k) draw();
    }
  }
  second();
}