#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void solve() {
  int n;
  cin>>n;
  vector<vi> g(n);
  rep(i,1,n) {
    int x, y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  vi ans(n), below(n);
  function<void(int,int,int)> dfs = [&](int x, int p, int depth) {
    for(int y : g[x]) if(y != p) {
      dfs(y,x,depth+1);
      below[x] += below[y];
    }
    if(depth == 0) ans[x] = -below[x];
    else if(depth%2==0) ans[x] = 1-below[x];
    else ans[x] = -1-below[x];
    below[x] += ans[x];
  };
  dfs(0,-1,0);

  rep(i,0,n) cout << ans[i] << " ";
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin>>T;
  rep(i,0,T) solve();
}