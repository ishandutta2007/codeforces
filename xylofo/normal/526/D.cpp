#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

vi pi(const string& s) {
  vi p(sz(s));
  rep(i,1,sz(s)) {
    int g = p[i-1];
    while (g && s[i] != s[g]) g = p[g-1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vi p = pi(s);
  rep(i,1,n+1) {
    int q = p[i-1], a = i-q, rp = i/a, ss = rp >= k ? rp/k : 1;
    // s[0..q) == s[a ... i)
    bool ans = false;
    if(rp/ss == k) ans = true; // B non-empty
    if(rp % (k+1) == 0 && i % a == 0) ans = true; // B empty
    debug(s.substr(0,i));
    debug(i,rp,q,a,k,ss);
    cout << ans;
  }
  cout << endl;
}