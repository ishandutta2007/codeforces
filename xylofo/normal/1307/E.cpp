#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

const ll md = 1e9+7;

ll cnt(ll l, ll r, ll lr) {
  return (l*r%md + l*lr%md + r*lr%md + lr*(lr-1)%md)%md;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  //n = m = 5000;
  vi s(n), f(m), h(m);
  rep(i,0,n) cin >> s[i];
  rep(i,0,m) cin >> f[i] >> h[i];
  //jkkkkrep(i,0,n) s[i] = rand()%2;
  //jkkkkrep(i,0,m) f[i] = rand()%2, h[i] = rand()%n;

  vi rl(m,n), rr(m,-1);
  vi idx(n+5);
  rep(i,0,m) {
    int hh = h[i];
    rep(j,0,n) if(s[j] == f[i]) {
      --hh;
      if(hh == 0) {
        rl[i] = j;
        break;
      }
    }
    hh = h[i];
    for(int j = n; j--;) if(s[j] == f[i]) {
      --hh;
      if(hh == 0) {
        rr[i] = j;
        break;
      }
    }
    idx[rl[i]+1]++;
    //debug(rl[i], rr[i]);
  }

  ll cows = 0, ans = 0;
  rep(p,-1,n) {
    ll col = p == -1 ? -1 : s[p], fix = idx[p+1];
    //rep(i,0,m) if(rl[i] == p) {
    //  //if(col != -1) assert(col == f[i]);
    //  col = f[i];
    //  ++fix;
    //}
    if(fix == 0 && p != -1) continue;

    vi l(n+1), r(n+1), lr(n+1);
    rep(i,0,m) {
      if(f[i] != col) {
        if(rl[i] < p && rr[i] > p) lr[f[i]]++;
        else if(rl[i] < p) l[f[i]]++;
        else if(rr[i] > p) r[f[i]]++;
      }
      else {
        if(rl[i] == p && rr[i] > p) lr[f[i]]++;
        else if(rl[i] == p) l[f[i]]++;
        else if(rr[i] > p) r[f[i]]++;
      }
    }

    ll ccows = 0, cans = 1;
    rep(i,0,n+1) if(l[i] + r[i] + lr[i]){
      ll s = cnt(l[i],r[i],lr[i]);
      ll cc = 2;
      if(s == 0) {
        s = l[i] + r[i] + 2*lr[i];
        if(i == col) {
          s = l[i] + lr[i];
        }
        if(s == 0) continue;
        cc = 1;
      }
      //debug(i,col,cc,s);
      ccows += cc;
      cans = (cans * s) % md;
    }
    //debug(p, ccows, cans);
    if(ccows > cows) {
      cows = ccows;
      ans = 0;
    }
    if(ccows == cows) {
      ans = (ans + cans) % md;
    }
  }

  cout << cows << " " << ans << endl;
}