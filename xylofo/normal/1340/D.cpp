#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<vi> g(n);
  rep(i,1,n) {
    int a,b;
    cin>>a>>b;
    --a,--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int mx = 0;
  rep(i,0,n) mx = max(mx, sz(g[i]));
  vector<pii> ans;
  function<void(int,int,int)> dfs = [&](int x, int t, int p) {
    int l = t, r = t + sz(g[x]);
    ans.emplace_back(x, t);
#define OK if(t == mx) { t = mx - sz(g[x]); ans.emplace_back(x,t); }
    for(auto y:g[x]) if(y != p) {
      OK
      ++t;
      dfs(y, t, x);
      ans.emplace_back(x,t);
    }
    if(l && t != l-1) ans.emplace_back(x,l-1);
  };
  dfs(0,0,-1);

  cout << sz(ans) << endl;
  for(auto [v,t] : ans)
    cout << v+1 << " " << t << "\n";
}