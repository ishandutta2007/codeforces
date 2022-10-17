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
  int n;
  cin >> n;
  n *= 2;
  string s;
  cin>>s;
  vi pref(n+1,0);
  rep(i,0,n) pref[i+1] = pref[i] + (s[i] == '(' ? +1 : -1);
  debug(pref);
  assert(pref[n] == 0);
  if(count(all(pref),-1) == 0) {
    cout << 0 << "\n";
    return;
  }
  int best_pref = 0;
  int best_suf = n;
  rep(i,0,n+1) {
    if(pref[i] >= pref[best_pref]) best_pref = i;
    if(pref[i] < 0) break;
  }
  for(int i = n; i>=0; --i) {
    if(pref[i] >= pref[best_suf]) best_suf = i;
    if(pref[i] < 0) break;
  }
  int best = max_element(all(pref))-begin(pref);

  auto check = [&](vector<pii> rev){
    //debug(rev);
    string q = s;
    for(auto [a,b] : rev) reverse(begin(q)+a, begin(q)+b);
    //debug(q);
    vi pref(n+1,0);
    rep(i,0,n) pref[i+1] = pref[i] + (q[i] == '(' ? +1 : -1);
    assert(pref[n] == 0);
    if(count(all(pref),-1) == 0) {
      cout << sz(rev) << "\n";
      for(auto [a,b] : rev) cout << a+1 << " " << b << "\n";
      return true;
    }
    return false;
  };

  //debug(best_pref, best_suf, best);

  if(check({{best_pref, best_suf}})) return;
  int ok = check({{0,best},{best,n}});
  assert(ok);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}