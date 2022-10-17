#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve(int tc) {
  int n;
  cin>>n;
  int cnt = 0;
  map<int,int> to_small;
  vector<pii> ed;
  vector<vi> l(n), r;
  rep(i,0,n) {
    int k;
    cin>>k;
    rep(j,0,k) {
      int x;
      cin>>x;
      if(!to_small.count(x)) {
        to_small[x] = cnt++;
        r.emplace_back();
      }
      x = to_small[x];
      ed.emplace_back(i,x);
      l[i].push_back(x);
      r[x].push_back(i);
    }
  }

  auto to_ll = [&](int x, int y) {
    if(y < x) swap(x,y);
    return x + (ll(y) << 30L);
  };

  unordered_map<ll,int> l_found, r_found;
  for(auto [x,y] : ed) {
    if(sz(l[x]) < sz(r[y])) {
      for(auto yy : l[x]) if(yy != y) {
        ll key = to_ll(y,yy);
        if(l_found.count(key)) {
          int t = l_found[key];
          if(x == t) continue;
          cout << x+1 << " " << t + 1 << "\n";
          return;
        }
        l_found[key] = x;
      }
    }
    else {
      for(auto xx : r[y]) if(xx != x) {
        ll key = to_ll(x,xx);
        if(r_found.count(key)) {
          int t = r_found[key];
          if(y == t) continue;
          cout << x+1 << " " << xx+1 << "\n";
          return;
        }
        r_found[key] = y;
      }
    }
  }

  cout << -1 << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}