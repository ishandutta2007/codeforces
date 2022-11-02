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
template<class T> void print(deque<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}
typedef tuple<int,int,int,int> ti;

int N, Q;
vector<vector<int>> G;
vector<vector<pii>> T;
vector<int> num, fromNum, depth, l, r;
int C;

#define log2(x) (31 - __builtin_clz(x))

struct sparse_table {
  int n;
  vector<int> a;
  vector<vector<int>> st;
  int combine(int dl, int dr) {
    return a[dl] > a[dr] ? dl : dr;
  }
  sparse_table() {}
  sparse_table(vector<int> & a) : n(sz(a)), a(a), st(log2(n) + 1, vector<int>(n)) {
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
  lowest_common_ancestor(vector<vector<int>> & e, int r) : n(sz(e)), a(n), v(2 * n - 1), h(2 * n - 1), e(e) {
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

void dfs(int cur, int par){
  num[cur] = C++;
  l[num[cur]] = num[cur];
  fromNum[num[cur]] = cur;
  for(int x : G[cur]){
    if(x != par){
      depth[x] = depth[cur]+1;
      dfs(x, cur);
    }
  }
  r[num[cur]] = C-1;
}

void build(deque<int> & res){
  int cur = res[0];
  res.pop_front();
  while(sz(res) && res[0] >= l[cur] && res[0] <= r[cur]){
    T[cur].push_back({res[0], depth[fromNum[res[0]]]-depth[fromNum[cur]]});
    T[res[0]].push_back({cur, depth[fromNum[res[0]]]-depth[fromNum[cur]]});
    build(res);
  }
}


deque<int> buildTree(vector<int> & cur, lowest_common_ancestor & lca){
  //print(cur);
  deque<int> res(cur.begin(), cur.end());
  for(int i=0; i<sz(cur)-1; i++){
    res.push_back(num[lca.lca(fromNum[cur[i]], fromNum[cur[i+1]])]);
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  //print(res);
  return res;
}

void buildTree2(deque<int> res){
  build(res);
  //print(T);
  //cerr << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  G.resize(N); num.resize(N); fromNum.resize(N);
  l.resize(N); r.resize(N); depth.resize(N); T.resize(N);
  for(int i=0; i<N-1; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  lowest_common_ancestor lca(G, 0);
  cin >> Q;
  vector<char> vis(N);
  vector<int> vir(N);
  while(Q--){
    int k, m;
    cin >> k >> m;
    vector<int> cur, v(k), s(k), imp(m);
    priority_queue<ti, vector<ti>, greater<ti>> PQ;
    for(int i=0; i<k; i++){
      cin >> v[i] >> s[i];
      v[i]--;
      cur.push_back(num[v[i]]);
      PQ.push({0, i, num[v[i]], 0});
    }
    for(int i=0; i<m; i++){
      cin >> imp[i];
      imp[i]--;
      cur.push_back(num[imp[i]]);
    }
    sort(cur.begin(), cur.end());
    cur.erase(unique(cur.begin(), cur.end()), cur.end());
    deque<int> allV = buildTree(cur, lca);
    buildTree2(allV);
    for(int x : allV)
      vis[x] = false;
    while(!PQ.empty()){
      auto [dist, ind, cur, totStep] = PQ.top(); PQ.pop();
      if(vis[cur])
        continue;
      //cerr << cur << ": " << ind << "; " << dist << " " << totStep << endl;
      vis[cur] = true;
      vir[cur] = ind;
      for(auto [x,d] : T[cur]){
        if(!vis[x]){
          int newDist = (totStep+d+s[ind]-1)/s[ind];
          int newTot = totStep+d;
          PQ.push({newDist, ind, x, newTot});
        }
      }
    }
    //print(vir);
    for(int x : imp){
      cout << vir[num[x]]+1 << " ";
    }
    cout << "\n";
    for(int x : allV)
      T[x].clear();
  }
}