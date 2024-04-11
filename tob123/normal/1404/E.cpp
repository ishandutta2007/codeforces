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

struct dinic {
  struct edge {
    ll j, c, f;
  };
  vector<edge> e;
  vector<vector<int>> adj;
  vector<int> lvl, ptr;
  int n, m = 0;
  queue<int> q;
  dinic(int n) : n(n), adj(n), lvl(n), ptr(n) {}
  void addEdge(int i, int j, ll c) {
    e.push_back({j, c, 0});
    e.push_back({i, 0, 0});
    adj[i].push_back(m++);
    adj[j].push_back(m++);
  }
  bool bfs(int s, int t) {
    fill(lvl.begin(), lvl.end(), -1);
    lvl[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int i : adj[v])
        if (e[i].c > e[i].f && lvl[e[i].j] < 0) {
          lvl[e[i].j] = lvl[v] + 1;
          q.push(e[i].j);
        }
    }
    return lvl[t] != -1;
  }
  ll dfs(int v, int t, ll push) {
    if (push == 0 || v == t)
      return push;
    for (int& idx = ptr[v]; idx < (int)adj[v].size(); idx++) {
      int id = adj[v][idx];
      if (lvl[v] + 1 != lvl[e[id].j] || e[id].c == e[id].f)
        continue;
      ll f = dfs(e[id].j, t, min(push, e[id].c - e[id].f));
      if (f != 0) {
        e[id].f += f;
        e[id ^ 1].f -= f;
        return f;
      }
    }
    return 0;
  }
  ll maxFlow(int s, int t) {
    ll ret = 0;
    while (bfs(s, t)) {
      fill(ptr.begin(), ptr.end(), 0);
      while (ll f = dfs(s, t, 1e18))
        ret += f;
    }
    return ret;
  }
};

const int n = 202;

int N, M;
bool A[n][n];

int getHoriz(int r, int c){
  return (M+5)*r+c;
}
int getVert(int r, int c){
  return (M+5)*(N+5) + (M+5)*r+c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  int tot = 0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      char c;
      cin >> c;
      A[i][j] = c=='#';
      tot += A[i][j];
    }
  }
  dinic F((N+5)*(M+5)*3);
  int cntE = 0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      F.addEdge(getHoriz(i, j), getVert(i, j), 1);
      F.addEdge(getHoriz(i, j), getVert(i-1, j), 1);
      F.addEdge(getHoriz(i, j-1), getVert(i, j), 1);
      F.addEdge(getHoriz(i, j-1), getVert(i-1, j), 1);
      if(A[i][j] && A[i][j+1]){
        F.addEdge(0, getHoriz(i, j), 1);
        cntE++;
      }
      if(A[i][j] && A[i+1][j]){
        F.addEdge(getVert(i, j), 1, 1);
        cntE++;
      }
    }
  }
  cout << tot - (cntE - F.maxFlow(0, 1)) << endl;
}