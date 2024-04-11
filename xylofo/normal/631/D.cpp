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

using String = vector<pair<ll,char>>;

vi pi(const String& s) {
  vi p(sz(s));
  rep(i,1,sz(s)) {
    int g = p[i-1];
    while (g && s[i] != s[g]) g = p[g-1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

vi match(const String& s, const String& pat) {
  String pp(pat);
  pp.emplace_back(-1,'$');
  pp.insert(pp.end(), all(s));
  vi p = pi(pp), res;
  rep(i,sz(p)-sz(s),sz(p))
    if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
  return res;
}

pair<ll,char> read(){
  string s;
  cin>>s;
  char c = s.back();
  s.pop_back();
  s.pop_back();
  ll k = stoll(s);
  return {k,c};
}

void read(int n, String& s){
  char lst = '$',c;
  ll k;
  rep(i,0,n) {
    tie(k,c) = read();
    if(c != lst) {
      s.emplace_back(0,c);
    }
    s.back().first += k;
    lst = c;
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  String s, pat;
  read(n,s);
  read(m,pat);
  ll ans = 0;
  if(pat.size() == 1) {
    debug(s);
    debug(pat);
    rep(i,0,sz(s)) if(pat[0].second == s[i].second) {
      ans += max<ll>(0, s[i].first - pat[0].first + 1);
    }
  }
  else {
    String p(pat.begin()+1, pat.end()-1);
    debug(s);
    debug(pat);
    debug(p);
    vi ma = match(s, p);
    int q = sz(pat)-1;
    for(int i : ma) {
      int x = i-1, y = i+sz(p);
      if(x < 0 || y >= sz(s)) continue;
      if(s[x].second != pat[0].second || s[x].first < pat[0].first) continue;
      if(s[y].second != pat[q].second || s[y].first < pat[q].first) continue;
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}