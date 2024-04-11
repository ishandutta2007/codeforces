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

const int n = 1e6+10;
int N, Q;

vector<vector<pii>> T;
int X[n];
int Par[n];
pii intv[n];
int newNum[n];
int cmp[n];

#define log2(x) (31 - __builtin_clz(x))

struct fenwick_tree {
  int n;
  vector<int> a, f;
  fenwick_tree(int n = 0) : n(n), a(n), f(n + 1) {}
  fenwick_tree(vector<int> & a) : fenwick_tree(a.size()) {
    for (int i = 0; i < n; i++)
      setValue(i, a[i]);
  }
  void changeValue(int i, int d) {
    for (a[i++] += d; i <= n; i += i & -i)
      f[i] += d;
  }
  void setValue(int i, int v) {
    changeValue(i, v - a[i]);
  }
  int getSum(int i) {
    int s = 0;
    for (i++; i; i -= i & -i)
      s += f[i];
    return s;
  }
  // get the sum of the range [l, r[
  int getSum(int l, int r) {
    return getSum(r - 1) - getSum(l - 1);
  }
};

struct sparse_table {
  int n;
  vector<int> a;
  vector<vector<int>> st;
  int combine(int dl, int dr) {
    return a[dl] > a[dr] ? dl : dr;
  }
  sparse_table() {}
  sparse_table(vector<int> & a) : n(a.size()), a(a), st(log2(n) + 1, vector<int>(n)) {
    for (int i = 0; i < n; i++)
      st[0][i] = i;
    for (int j = 1; 1 << j <= n; j++)
      for (int i = 0; i + (1 << j) <= n; i++)
        st[j][i] = combine(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  // query the data on the range [l, r[
  int query(int l, int r) {
    int s = log2(r - l);
    return combine(st[s][l], st[s][r - (1 << s)]);
  }
};

struct lowest_common_ancestor {
  int n, m = 0;
  vector<int> a, v, h;
  vector<vector<int>>& e;
  sparse_table st;
  lowest_common_ancestor(vector<vector<int>> & e, int r) : n(e.size()), a(n), v(2 * n - 1), h(2 * n - 1), e(e) {
    dfs(r);
    st = sparse_table(h);
  }
  void dfs(int i, int p = -1, int d = 0) {
    a[i] = m; v[m] = i; h[m++] = d;
    for (int j : e[i]) {
      if (j == p)
        continue;
      dfs(j, i, d - 1);
      v[m] = i; h[m++] = d;
    }
  }
  // calculate the lowest common ancestor of x and y
  int lca(int x, int y) {
    return v[st.query(min(a[x], a[y]), max(a[x], a[y]) + 1)];
  }
};

fenwick_tree BIT(n);

void initDSU(){
  for(int i=0; i<N; i++){
    cmp[i] = i;
  }
}
int find(int x){
  if(cmp[x] != x)
    cmp[x] = find(cmp[x]);
  return cmp[x];
}
void combine(int a, int b){
  cmp[find(a)] = find(b);
}
int newN = 0;
void dfs(int cur, int par){
  newNum[cur] = newN;
  int l = newN++;
  for(auto [x, w] : T[cur]){
    if(x == par)
      continue;
    Par[x] = cur;
    X[x] = X[cur]^w;
    dfs(x, cur);
  }
  intv[cur] = make_pair(l, newN-1);
}

void mark(int x){
  auto [l, r] = intv[x];
  BIT.changeValue(l, 1);
  BIT.changeValue(r+1, -1);
}
void markPath(int x, int to){
  while(x != to){
    mark(x);
    x = Par[x];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  T.resize(N);
  vector<tuple<int,int,int>> A;
  initDSU();
  for(int i=0; i<Q; i++){
    int u, v, x;
    cin >> u >> v >> x;
    u--; v--;
    A.emplace_back(u, v, x);
    if(find(u) != find(v)){
      T[u].emplace_back(v, x);
      T[v].emplace_back(u, x);
      combine(u, v);
    }
  }
  for(int i=1; i<N; i++){
    if(find(i) != find(0)){
      combine(0, i);
      T[0].emplace_back(i, 0);
      T[i].emplace_back(0, 0);
    }
  }
  initDSU();
  dfs(0, -1);
  vector<vector<int>> e(N);
  for(int i=0; i<N; i++){
    for(int j=0; j<sz(T[i]); j++)
      e[i].push_back(T[i][j].first);
  }
  lowest_common_ancestor LCA(e, 0);
  for(auto [u, v, x] : A){
    //cout << u << " " << v << " " << X[u] << " " << X[v] << endl;
    if(find(u) != find(v)){
      combine(u, v);
      cout << "YES\n";
    }
    else if((X[u] ^ X[v] ^ x) == 1){ 
      int lca = LCA.lca(u, v);
      //cout << "lca: " << lca << endl;
      int sum = BIT.getSum(newNum[u]) + BIT.getSum(newNum[v]) - 2*BIT.getSum(newNum[lca]);
      //cout << "sum: " << sum << endl;
      if(sum == 0){
        cout << "YES\n";
        markPath(v, lca);
        markPath(u, lca);
      }
      else
        cout << "NO\n";
    }
    else
      cout << "NO\n";
  }
}