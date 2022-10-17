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

struct T {
  ll sum = 0;
  ll max_sum = 0;
  ll max_pre = 0;
  ll max_suf = 0;
};
T from(int x) {
  T res;
  res.sum = x;
  res.max_sum = res.max_pre = res.max_suf = max(x,0);
  return res;
}
T f(T a, T b) {
  T res;
  res.sum = a.sum + b.sum;
  res.max_pre = max(a.max_pre, a.sum + b.max_pre);
  res.max_suf = max(a.max_suf + b.sum, b.max_suf);
  res.max_sum = max({a.max_sum, b.max_sum, a.max_suf + b.max_pre});
  return res;
}

constexpr T unit;

struct Tree {
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}

  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
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
  int n, q, x;
  cin >> n >> q;
  vi v(n);
  rep(i,0,n) { cin>>x; v[i] += x; }
  rep(i,0,n) { cin>>x; v[i] -= x; }
  debug(v);

  Tree pos(n), neg(n);
  rep(i,0,n) {
    pos.update(i,from(v[i]));
    neg.update(i,from(-v[i]));
  }

  rep(i,0,q) {
    int l, r;
    cin>>l>>r;
    --l;
    auto po = pos.query(l,r);
    auto ne = neg.query(l,r);
    debug(l,r,po,ne);
    bool ok = true;
    if(po.sum != 0) ok = false;
    else if(po.max_pre != 0) {
      assert(ne.max_suf != 0);
      ok = false;
    }
    if(!ok) cout << -1 << "\n";
    else {
      assert(ne.max_sum == po.max_sum);
      cout << po.max_sum << "\n";
    }
  }
}