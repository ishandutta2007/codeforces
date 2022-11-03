#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

struct segment_tree {
  struct data{
    ll bp=0;
    ll bm=0;
    ll p=0;
    ll m=0;
  };
  struct operation{
  };
  static void print(data d){
    cout << "bp: " << d.bp << ", bm: " << d.bm << ", p: " << d.p << ", m: " << d.m << endl;
  }
  static data combine(data dl, data dr){
    //cout << "combine:" << endl;
    //print(dl);
    //print(dr);
    ll bp=0, bm=0, p=0, m=0;
    ll x = min(dl.p, dr.m);
    bp += x; dl.p -= x; dr.m -= x;
    x = min(dl.m, dr.p);
    bm += x; dl.m -= x; dr.p -= x;

    x = min(dl.m, dr.bp);
    m += x; dl.m -= x; dr.bp -= x;
    x = min(dl.p, dr.bm);
    p += x; dl.p -= x; dr.bm -= x;

    x = min(dl.bp, dr.p);
    p += x; dl.bp -= x; dr.p -= x;
    x = min(dl.bm, dr.m);
    m += x; dl.bm -= x; dr.m -= x;

    m += dl.m + dr.m;
    p += dl.p + dr.p;

    x = min(dl.bp, dr.bp);
    bp += x; dl.bp -= x; dr.bp -= x;
    x = min(dl.bm, dr.bm);
    bm += x; dl.bm -= x; dr.bm -= x;

    bp += dl.bp + dr.bp;
    bm += dl.bm + dr.bm;
    data res {bp, bm, p, m};
    //print(res);
    return res;
  };
  static data calculate(operation o, data d){ return d; }
  static operation merge(operation ot, operation ob){ return ot; }
  int n, h;
  vector<data> t;
  vector<operation> o;
  segment_tree(int n = 0) : n(n), h(32 - __builtin_clz(n)), t(2 * n), o(n) {}
  segment_tree(vector<data> & a) : segment_tree(a.size()) {
    for (int i = 0; i < n; i++)
      t[i + n] = a[i];
    for (int x = n - 1; x > 0; x--)
      t[x] = combine(t[x << 1], t[x << 1 | 1]);
  }
  void apply(int x, operation op) {
    t[x] = calculate(op, t[x]);
    if (x < n)
      o[x] = merge(op, o[x]);
  }
  void push(int x) {
    for (int s = h; s > 0; s--) {
      int c = x >> s;
      apply(c << 1, o[c]);
      apply(c << 1 | 1, o[c]);
      o[c] = operation();
    }
  }
  void build(int x) {
    while (x >>= 1)
      t[x] = calculate(o[x], combine(t[x << 1], t[x << 1 | 1]));
  }
  // set the data at the position i
  void setValue(int i, data d) {
    i += n;
    push(i);
    t[i] = d;
    build(i);
  }
  // query the data on the range [l, r[
  data query(int l, int r) {
    l += n; r += n;
    push(l); push(r - 1);
    data dl = {0,0,0,0}, dr = {0,0,0,0};
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        dl = combine(dl, t[l++]);
      if (r & 1)
        dr = combine(t[--r], dr);
    }
    return combine(dl, dr);
  }
  // apply an operation on the range [l, r[
  void apply(int l, int r, operation op) {
    l += n; r += n;
    push(l); push(r - 1);
    int xl = l, xr = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        apply(l++, op);
      if (r & 1)
        apply(--r, op);
    }
    build(xl); build(xr - 1);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  segment_tree S(N);
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    ll x;
    cin >> x;
    A[i] -= x;
    A[i] *= -1;
    if(A[i] < 0)
      S.setValue(i, {0, 0, 0, abs(A[i])});
    else if(A[i] >= 0)
      S.setValue(i, {0, 0, abs(A[i]), 0});
  }
  /*
  S.print(S.query(7, 8));
  S.print(S.query(6, 7));
  S.print(S.query(6, 8));
  */
  for(int i=0; i<Q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    auto res = S.query(l, r);
    //S.print(res);
    if(res.bm + res.m + res.p > 0)
      cout << -1 << "\n";
    else{
      ll x = res.bp;
      cout << x << "\n";
    }
  }
}