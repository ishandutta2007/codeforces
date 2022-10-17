#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
//#define debug(x) cerr << "[ " << #x << " = " << x << " ]" <<endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

struct FT {
  vi s;
  FT(int n) : s(n) {}
  void update(int pos, int dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) { // sum of values in [0, pos)
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  rep(i,0,sz(a)) {
    cin>>a[i];
    //a[i] = rand()%int(1e9);
  }
  rep(i,0,sz(b)) {
    cin>>b[i];
    //b[i] = rand()%int(1e9);
  }
  sort(all(b));
  vi xs = a;
  for(int x : b) xs.emplace_back(x);
  sort(all(xs));
  auto compress = [&](int x) { return int(lower_bound(all(xs), x) - begin(xs)); };

  for(int& x : a) x = compress(x);
  for(int& x : b) x = compress(x);

  FT l(sz(xs)), r(sz(xs));
  rep(i,0,n) r.update(a[i],+1);
  int pos = 0; // just before pos
  auto move_right = [&](){
    r.update(a[pos],-1);
    l.update(a[pos],+1);
    ++pos;
  };
  auto move_left = [&](){
    --pos;
    r.update(a[pos],+1);
    l.update(a[pos],-1);
  };
  auto mv = [&](int target){
    while(pos > target) move_left();
    while(pos < target) move_right();
  };
  auto query = [&](int x){
    int bad_left = l.query(sz(xs)) - l.query(x+1);
    int bad_right = r.query(x);
    return bad_left + bad_right;
  };

  vi cost(m,1e9);
  function<void(int,int,int,int)> solve = [&](int l, int r, int lo, int hi) { // [l,r), [lo,hi)
    if(l >= r) return;
    int q = l + (r-l)/2;
    int opt = -1;
    mv(lo);
    int c = query(b[q]);
    rep(i,lo,hi) {
      //mv(i);
      //assert(c == query(b[q]));
      if(c < cost[q]) cost[q] = c, opt = i;
      if(i+1 < hi){
        if(b[q] > a[i]) --c;
        else if(b[q] < a[i]) ++c;
      }
    }
    assert(opt != -1);
    solve(l,q, lo,opt+1);
    solve(q+1,r, opt,hi);

    //debug(q); debug(opt); debug(cost[q]);
  };
  solve(0,m,0,n+1);

  ll ans = 0;
  rep(i,0,n) { mv(i); ans += r.query(a[i]); }

  debug(ans);

  rep(i,0,m) ans += cost[i];
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin>>t;
  rep(i,0,t) solve();
}