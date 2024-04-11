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

int N, M;
const ll MOD = 998244353;
vector<int> A;

ll pos(int x){
  if(x < 10 || x > 18)
    return 0;
  else
    return 18-x+1;
}

struct segment_tree {
  struct data{
    ll v[2][2] = {{0,0},{0,0}};
    int l=0, r=0;
    bool neutr = true;
  };
  struct operation{};
  static void print(segment_tree::data d){
    cerr << d.l << "-" << d.r << ": " << d.v[0][0] << " " << d.v[0][1] << " " << d.v[1][0] << " " << d.v[1][1] << endl;
  }
  static data combine(data dl, data dr){
    //print(dl); print(dr); cerr << "->" << endl;
    if(dl.neutr)
      return dr;
    if(dr.neutr)
      return dl;
    data nxt;
    nxt.neutr = false;
    nxt.l=dl.l; nxt.r = dr.r;
    for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
        nxt.v[i][j] = dl.v[i][0] * dr.v[0][j] % MOD;
        nxt.v[i][j] += dl.v[i][1] * dr.v[1][j] % MOD * pos(10*A[dl.r]+A[dr.l]);
        nxt.v[i][j] %= MOD;
      }
    }
    //print(nxt); cerr << endl;
    return nxt;
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
  cin >> N >> M;
  segment_tree S(N);
  segment_tree::data cur;
  cur.neutr = false;
  A.resize(N);
  for(int i=0; i<N; i++){
    char c;
    cin >> c;
    int x = c-'0';
    A[i] = x;
    cur.l = cur.r = i;
    cur.v[0][0] = x+1;
    cur.v[0][1] = 1;
    cur.v[1][0] = 1;
    cur.v[1][1] = 0;
    S.setValue(i, cur);
  }
  for(int i=0; i<M; i++){
    int x, d;
    cin >> x >> d;
    x--;
    A[x] = d;
    cur.v[0][0] = d+1;
    cur.v[0][1] = 1;
    cur.v[1][0] = 1;
    cur.v[1][1] = 0;
    cur.l = cur.r = x;
    S.setValue(x, cur);
    cout << S.query(0, N).v[0][0] << "\n";
  }
}