#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,v) for(auto& x: v)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<int> vsi;

struct TwoSat {
  int N;
  vector<vi> gr;
  vi values; // 0 = false, 1 = true

  TwoSat(int n = 0) : N(n), gr(2*n) {}

  int add_var() { // (optional)
    gr.emplace_back();
    gr.emplace_back();
    return N++;
  }

  void either(int f, int j) {
    f = max(2*f, -1-2*f);
    j = max(2*j, -1-2*j);
    gr[f^1].push_back(j);
    gr[j^1].push_back(f);
  }
  void set_value(int x) { either(x, x); }

  void at_most_one(const vi& li) { // (optional)
    if (sz(li) <= 1) return;
    int cur = ~li[0];
    rep(i,2,sz(li)) {
      int next = add_var();
      either(cur, ~li[i]);
      either(cur, next);
      either(~li[i], next);
      cur = ~next;
    }
    either(cur, ~li[1]);
  }

  vi val, comp, z; int time = 0;
  int dfs(int i) {
    int low = val[i] = ++time, x; z.push_back(i);
    trav(e, gr[i]) if (!comp[e])
      low = min(low, val[e] ?: dfs(e));
    ++time;
    if (low == val[i]) do {
      x = z.back(); z.pop_back();
      comp[x] = time;
      if (values[x>>1] == -1)
        values[x>>1] = !(x&1);
    } while (x != i);
    return val[i] = low;
  }

  bool solve() {
    values.assign(N, -1);
    val.assign(2*N, 0); comp = val;
    rep(i,0,2*N) if (!comp[i]) dfs(i);
    rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
    return 1;
  }

  vector<vsi> comp_graph;
  vector<vsi> comp_graph_r;
  vector<vsi> comp_vert;
  vi comp_rep;
  vi comp_assign;
  vi comp_deg;

  void lex(){
    int mx = 0;
    rep(i,0,2*N) mx = max(mx,comp[i]+1);
    comp_graph.resize(mx);
    comp_graph_r.resize(mx);
    comp_assign.resize(mx,-1);
    comp_rep.assign(mx,-1);
    comp_vert.resize(mx);
    comp_deg.resize(mx);
    rep(i,0,2*N) {
      int x = comp[i];
      comp_vert[x].emplace_back(i);
      if(comp_rep[x] == -1) {
        if(i % 2 == 0) comp_rep[x] = i;
        else comp_rep[x] = 1e9-i;
      }
      trav(e,gr[i]) {
        int y = comp[e];
        if(y == x) continue;
        comp_graph[x].emplace_back(y);
        comp_graph_r[y].emplace_back(x);
      }
    }
    rep(x,0,mx) {
      sort(all(comp_graph[x]));
      sort(all(comp_graph_r[x]));
      comp_graph[x].resize(unique(all(comp_graph[x]))-comp_graph[x].begin());
      comp_graph_r[x].resize(unique(all(comp_graph_r[x]))-comp_graph_r[x].begin());
      comp_deg[x] = comp_graph[x].size();
    }
    priority_queue<pair<int,int> > q;
    rep(i,0,mx) if(comp_deg[i] == 0) {
      if(comp_vert[i].size() == 0) continue;
      q.emplace(-comp_rep[i], i);
    }
    while(!q.empty()) {
      int x = q.top().second;
      q.pop();
      if(comp_vert[x].size() == 0) continue;
      if(comp_assign[x] == -1) {
        comp_assign[x] = 1;
        for(int i:comp_vert[x]) {
          int y = comp[i^1];
          comp_assign[y] = 0;
        }
        for(int y:comp_graph_r[x]){
          --comp_deg[y];
          if(comp_deg[y] == 0) {
            q.emplace(-comp_rep[y], y);
          }
        }
      }
    }
    rep(i,0,N) {
      values[i] = comp_assign[comp[2*i]];
    }
  }
};


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

void solve(int tc) {
  int n,m;
  cin>>n>>m;
  TwoSat sat0(n), sat1(n); // vals flipped in sat1
  rep(i,0,m) {
    int a, b;
    cin>>a>>b;
    --a,--b;
    sat0.either(~a, b);
    sat1.either(a, ~b);
  }
  vi jury, cats;
  sat0.set_value(~0);
  sat1.set_value(~0);
  if(sat0.solve()) {
    sat0.lex();
    int cnt = 0;
    rep(i,0,n) cnt += sat0.values[i];
    if(cnt != 0 && cnt != n) {
      rep(i,0,n) (sat0.values[i] ? jury : cats).push_back(i+1);
    }
  }
  if(sz(jury) == 0 && sat1.solve()) {
    sat1.lex();
    int cnt = 0;
    rep(i,0,n) cnt += sat1.values[i];
    if(cnt != 0 && cnt != n) {
      rep(i,0,n) (!sat1.values[i] ? jury : cats).push_back(i+1);
    }
  }
  if(sz(jury) == 0) cout << "No\n";
  else {
    cout << "Yes\n";
    cout << sz(jury) << " " << sz(cats) << "\n";
    for(int a:jury) cout << a << " ";
    cout << "\n";
    for(int a:cats) cout << a << " ";
    cout << "\n";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}