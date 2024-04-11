#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;
const ll MOD = 1e9+7;

#define log2(x) (31 - __builtin_clz(x))

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

int N, M;
vector<vector<pii>> G;
int num[n];
int C;
int cyc[n];
int dp[2*n];
vector<vector<int>> G2;
ll pw[n];

int dfs(int cur, int par){
  int eAct = -1;
  num[cur] = C++;
  for(auto p : G[cur]){
    int x, ind; tie(x, ind) = p;
    if(x == par) continue;
    if(num[x] == -1){
      int curRes = dfs(x, cur);
      if(curRes != -1)
        eAct = curRes;
    }
    else if(num[x] > num[cur]){
      cyc[cur] = eAct+N;
      eAct = -1;
    }
    else{
      eAct = ind;
    }
  }
  if(eAct != -1){
    cyc[cur] = N+eAct;
  }
  else if(cyc[cur] == -1){
    cyc[cur] = cur;
  }
  //cerr << "cur " << cur << " --> " << eAct << endl;
  return eAct;
}

void dfs2(int cur, int par){
  for(int x : G2[cur]){
    if(x != par){
      dp[x] += dp[cur];
      dfs2(x, cur);
    }
  }
}

void printG2(){
  for(int i=0; i<sz(G2); i++){
    if(sz(G2[i])){
      cerr << i << ":";
      for(int x : G2[i])
        cerr << " " << x;
      cerr << endl;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  G.resize(N);
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back({b, i});
    G[b].push_back({a, i});
  }
  int st = 0;
  for(int i=0; i<N; i++){
    if(sz(G[i]) > sz(G[st]))
      st = i;
  }
  fill_n(num, N, -1);
  fill_n(cyc, N, -1);
  dfs(st, -1);

  G2.resize(N+M);
  /*
  for(int i=0; i<N; i++){
    cerr << i+1 << " :: " << cyc[i] << endl;
  }
  */
  int r = 0;
  for(int i=0; i<N; i++){
    for(auto p : G[i]){
      if(cyc[p.first] != cyc[i]){
        //cerr << i << " -> " << cyc[i] << " " << cyc[p.first] << endl;
        G2[cyc[i]].push_back(cyc[p.first]);
      }
    }
    r = cyc[i];
    if(cyc[i] >= N)
      dp[cyc[i]] = 1;
  }
  //printG2();
  lowest_common_ancestor lca(G2, r);
  dfs2(r, -1);
  pw[0] = 1;
  for(int i=1; i<=N; i++){
    pw[i] = 2*pw[i-1]%MOD;
  }
  int K;
  cin >> K;
  for(int i=0; i<K; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    int anc = lca.lca(cyc[x], cyc[y]);
    //cerr << cyc[x] << " " << cyc[y] << " " << anc << endl;
    int res = dp[cyc[x]] + dp[cyc[y]] - 2*dp[anc];
    if(anc >= N) res++;
    cout << pw[res] << endl;
  }

  return 0;
}