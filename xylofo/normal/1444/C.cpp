#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct RollbackUF {
  vi e; vector<pii> st;
  RollbackUF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return sz(st); }
  void rollback(int t) {
    for (int i = time(); i --> t;)
      e[st[i].first] = st[i].second;
    st.resize(t);
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  vi col(n);
  rep(i,0,n) { cin>>col[i]; --col[i]; }
  RollbackUF uf(2*n);
  auto ae = [&](int a, int b) {
    uf.join(a, b+n);
    uf.join(a+n, b);
    return (uf.find(a) == uf.find(a+n));
  };

  vi bad_col(k);
  map<pii, vector<pii>> edges;
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    if(col[x] > col[y]) swap(x, y);
    if(col[x] == col[y]) {
      if(ae(x,y))
        bad_col[col[x]] = true;
    }
    else
      edges[{col[x],col[y]}].emplace_back(x,y);
  }

  ll good = count(all(bad_col),0);
  ll ans = good * (good-1) / 2;
  int T = uf.time();
  for(auto [c,ed] : edges) {
    if(bad_col[c.first] || bad_col[c.second]) continue;

    bool bad = false;
    for(auto [x,y] : ed) if(ae(x,y)) bad = true;
    if(bad) --ans;
    uf.rollback(T);
  }

  cout << ans << endl;
}