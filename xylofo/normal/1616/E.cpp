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

const ll inf = 1e18;


struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
};

void solve(int tc) {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  const int Q = 'z'-'a'+1;
  vector<vi> le(Q);
  for(int i = n; i--;) {
    rep(t,s[i]-'a',Q) le[t].emplace_back(i);
  }
  vi alive(n,1);

  auto next_le = [&](char x) {
    x -= 'a';
    if(x < 0) return -1;
    while(sz(le[x]) && !alive[le[x].back()]) le[x].pop_back();
    if(sz(le[x])) return le[x].back();
    return -1;
  };

  FT fw(n);
  rep(i,0,n) fw.update(i,+1);

  auto cost = [&](int i) {
    return fw.query(i);
  };
  auto kill = [&](int i) {
    fw.update(i,-1);
    alive[i] = 0;
  };


  //debug();
  ll ans = inf;
  ll cur = 0;
  rep(i,0,n) {
    //debug(t[i]);
    int r = next_le(t[i]-1);
    if(r != -1) {
      //debug("consider ", r, s[r], cost(r));
      ans = min(ans, cur + cost(r));
    }

    r = next_le(t[i]);
    if(r == -1) break;
    //debug("doing", r, s[r], cost(r));
    cur += cost(r);
    kill(r);
  }

  if(ans == inf) ans = -1;
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}