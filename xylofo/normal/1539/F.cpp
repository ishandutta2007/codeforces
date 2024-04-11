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

struct T { int sum, max_pre, max_suf; };
static constexpr T unit{0,0,0};

struct Tree {
  T f(T a, T b) {
    return T{a.sum + b.sum, max(a.max_pre, a.sum + b.max_pre), max(b.max_suf, a.max_suf + b.sum)};
  } // (any associative fn)
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}

  void update(int pos, int val) {
    for (s[pos += n] = T{val, max(val,0), max(val,0)}; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi v(n);
  rep(i,0,n) cin>>v[i];
  vi ans(n,0);


  for(int delta : {1,-1}) {
    Tree segtree(n);
    rep(i,0,n) segtree.update(i,-1);

    map<int,vi> by_val;
    rep(i,0,n) by_val[delta * v[i]].emplace_back(i);

    for(auto [v, idx] : by_val) {
      for(int i : idx) segtree.update(i,1);
      for(int i : idx) {
        int max_sum = segtree.query(0,i).max_suf + segtree.query(i+1,n).max_pre;
        ans[i] = max(ans[i], (max_sum + (delta==-1))/2);
      }
    }
  }

  rep(i,0,n) cout << ans[i] << " ";
  cout << endl;
}