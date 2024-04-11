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

const int n = 1e6;

int N, M, Q;
int P[n];
int P2[n];
vector<pii> E, q;
bool D[n];
int curInd = 0;

struct node{
  vector<int> ch;
  int l, r;
};

vector<int> C;
vector<node> child;

int find(int x){
  if(C[x] != x)
    C[x] = find(C[x]);
  return C[x];
}

void uni(int a, int b){
  int c1 = find(a);
  int c2 = find(b);
  if(c1 == c2)
    return;
  int newI = sz(C);
  C.push_back(newI);
  child.resize(sz(C));
  child[newI].ch.push_back(c1);
  child[newI].ch.push_back(c2);
  C[c1] = newI;
  C[c2] = newI;
}

void dfs(int cur){
  if(cur < N){
    child[cur].l = child[cur].r = curInd++;
  }
  else{
    for(int x : child[cur].ch){
      dfs(x);
    }
    child[cur].l = child[child[cur].ch[0]].l;
    child[cur].r = child[child[cur].ch.back()].r;
  }
}

struct segment_tree {
  struct data{
    bool neutr = true;
    int v;
  };
  struct operation{
    
  };
  static data combine(data dl, data dr){
    if(dl.neutr)
      return dr;
    if(dr.neutr)
      return dl;
    if(P2[dl.v] < P2[dr.v])
      return dr;
    else
      return dl;
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
  void setValue(int i) {
    i += n;
    push(i);
    //t[i] = d;
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
  cin >> N >> M >> Q;
  child.resize(N);
  for(int i=0; i<N; i++){
    cin >> P[i];
    C.push_back(i);
  }
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    E.emplace_back(a, b);
  }
  for(int i=0; i<Q; i++){
    int t, x;
    cin >> t >> x;
    x--;
    q.emplace_back(t, x);
    if(t == 2){
      D[x] = true;
    }
  }
  for(int i=0; i<M; i++){
    if(!D[i]){
      uni(E[i].first, E[i].second);
    }
  }
  for(int i=Q-1; i>=0; i--){
    auto [t, x] = q[i];
    if(t == 1){
      q[i].second = find(x);
    }
    else{
      uni(E[x].first, E[x].second);
    }
  }
  for(int i=0; i<sz(C); i++){
    if(C[i] == i)
      dfs(i);
  }
  vector<segment_tree::data> A(N);
  for(int i=0; i<N; i++){
    P2[child[i].l] = P[i];
    A[i].neutr = false;
    A[i].v = i;
  }
  segment_tree S(A);
  for(int i=0; i<Q; i++){
    auto [t, x] = q[i];
    if(t == 1){
      int res = S.query(child[x].l, child[x].r+1).v;
      cout << P2[res] << "\n";
      P2[res] = 0;
      S.setValue(res);
    }
  }
}