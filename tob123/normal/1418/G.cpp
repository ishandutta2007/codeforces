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
    int m = 1e6;
    int cnt = 0;
  };
  struct operation{
    int val = 0;
    operation(int val = 0) : val(val) {}
  };
  static data combine(data dl, data dr){
    if(dl.m < dr.m)
      return dl;
    if(dr.m < dl.m)
      return dr;
    data res = {dl.m, dl.cnt+dr.cnt};
    return res;
  }
  static data calculate(operation o, data d){
    d.m += o.val;
    return d;
  }
  static operation merge(operation ot, operation ob){
    ot.val += ob.val;
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

const int n = 5e5+10;

segment_tree S(5);

void addS(vector<int>& pos, int val){
  if(sz(pos)){
    int l1 = sz(pos) >= 3 ? pos[sz(pos)-3]+1 : 0;
    int r1 = pos.back()+1;
    S.apply(l1, r1, segment_tree::operation(val));
    if(sz(pos) > 3){
      S.apply(0, pos[sz(pos)-4]+1, segment_tree::operation(val));
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N), cnt(N);
  map<int,vector<int>> M;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  vector<segment_tree::data> dataS(N+1);
  for(int i=0; i<=N; i++){
    dataS[i].m = 0;
    dataS[i].cnt = 1;
  }
  S = segment_tree(dataS);
  int l = 0;
  ll R = 0;
  for(int i=0; i<N; i++){
    cnt[A[i]]++;
    addS(M[A[i]], -1);
    M[A[i]].push_back(i);
    addS(M[A[i]], 1);
    if(cnt[A[i]] == 3){
      while(A[l++] != A[i]){
      }
    }
    auto res = S.query(0, i+1);
    if(res.m == 0)
      R += res.cnt;
  }
  cout << R << endl;
}