#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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
    gr[f].push_back(j^1);
    gr[j].push_back(f^1);
  }
  void set_value(int x) { either(x, x); }
  void imply(int f, int j) { either(~f, j); }

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
    if (low == val[i]) do {
      x = z.back(); z.pop_back();
      comp[x] = low;
      if (values[x>>1] == -1)
        values[x>>1] = x&1;
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
};


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, p, M, m;
  cin >> n >> p >> M >> m;
  M += 5;

  TwoSat sat;
  vi L(M), R(M), v(p);
  trav(x, L) x = sat.add_var();
  trav(x, R) x = sat.add_var();
  trav(x, v) x = sat.add_var();

  rep(i,0,M-1) {
    sat.imply(~L[i], ~L[i+1]);
    sat.imply(~R[i+1], ~R[i]);
    sat.either(~R[i], ~L[i+1]);
  }
  sat.set_value(L[0]);
  sat.set_value(R[M-5]);

  rep(i,0,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    sat.either(v[x],v[y]);
  }
  rep(i,0,p) {
    int l,r;
    cin>>l>>r;
    sat.imply(v[i], L[l]);
    sat.imply(v[i], R[r]);
  }
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    sat.either(~v[x], ~v[y]);
  }

  bool b = sat.solve();
  if(!b) {
    cout << -1 << endl;
    return 0;
  }
  vi ans; int ff;
  rep(i,0,p) if(sat.values[v[i]]) ans.emplace_back(i);
  rep(i,0,M-1) {
    if(sat.values[L[i]] && !sat.values[L[i+1]]) ff = i;
  }

  rep(i,0,M) {
    int l = sat.values[L[i]];
    int r = sat.values[R[i]];
    debug(l, r);
  }

  cout << sz(ans) << " " << ff << endl;
  trav(x, ans) cout << x+1 << " ";
  cout << endl;
}