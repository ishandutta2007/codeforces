#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template<class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.emplace_back(sz(V) - pw * 2 + 1);
      rep(j,0,sz(jmp[k]))
        jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    assert(a < b); // or return inf if a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};

struct LCA {
  int T = 0;
  vi time, path, ret, depth;
  RMQ<int> rmq;

  LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1), ret)) {}
  void dfs(vector<vi>& C, int v, int par) {
    if(par != -1) depth[v] = depth[par] + 1;
    time[v] = T++;
    for (int y : C[v]) if (y != par) {
      path.push_back(v), ret.push_back(time[v]);
      dfs(C, y, v);
    }
  }

  int lca(int a, int b) {
    if (a == b) return a;
    tie(a, b) = minmax(time[a], time[b]);
    return path[rmq.query(a, b)];
  }
  int dist(int a, int b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

void solve(int tc) {
  int n, a, b, da, db;
  cin>>n>>a>>b>>da>>db;
  --a,--b;
  vector<vi> g(n);
  rep(i,0,n-1) {
    int x, y;
    cin>>x>>y;
    --x,--y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  LCA lca(g);
  if(lca.dist(a, b) <= da) { cout << "Alice" << endl; return; }

  int x = 0, y = 0;
  rep(i,0,n) if(lca.dist(0,i) > lca.dist(0,x)) x = i;
  rep(i,0,n) if(lca.dist(x,i) > lca.dist(x,y)) y = i;
  int diam = lca.dist(x,y);
  db = min(db, diam);
  da = min(da, diam);

  if(2*da >= db) { cout << "Alice" << endl; return; }

  cout << "Bob" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}