#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long llll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

llll INF = 1e15;

struct segment_tree {
  struct data{
    bool neutr = true;
    llll ll=-INF, lh=0, hh=-INF, hl=0;
  };
  struct operation{};
  static data combine(data dl, data dr){
    if(dl.neutr)
      return dr;
    if(dr.neutr)
      return dl;
    data r;
    r.neutr = false;
    r.ll = max(dl.ll + dr.hl, dl.lh + dr.ll);
    r.hh = max(dl.hh + dr.lh, dl.hl + dr.hh);
    r.lh = max(dl.lh + dr.lh, dl.ll + dr.hh);
    r.hl = max(dl.hl + dr.hl, dl.hh + dr.ll);
    return r;
  }
  static data calculate(operation o, data d){
    return d;
  }
  static operation merge(operation ot, operation ob){
    return ot;
  }
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
    data dl, dr;
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
  int T, N, Q;
  cin >> T;
  while(T--){
    cin >> N >> Q;
    vector<segment_tree::data> A(N);
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      A[i].neutr = false;
      A[i].hh = x;
      A[i].ll = -x;
    }
    segment_tree S(A);
    cout << S.query(0, N).hh << "\n";
    while(Q--){
      int l, r;
      cin >> l >> r;
      l--; r--;
      swap(A[l], A[r]);
      S.setValue(l, A[l]);
      S.setValue(r, A[r]);
      cout << S.query(0, N).hh << "\n";
    }
  }
}