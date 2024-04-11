#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) // ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<vi> g(n);
  rep(i,1,n) {
    int a, b;
    cin>>a>>b;
    --a,--b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  vi grundy(n), par(n);
  function<void(int,int)> dfs = [&](int x, int p) {
    par[x] = p;
    for(int y : g[x]) if(y != p) {
      dfs(y, x);
      grundy[x] ^= (1 + grundy[y]);
    }
  };
  dfs(0, -1);
  int gg = grundy[0];

  vi ans(n);
  rep(i,0,n) {
    int x = i;
    while(par[x] >= 0) {
      gg ^= grundy[x]^(grundy[x]+1)^1;
      tie(x, par[x]) = pii(par[x], -1);
    }
    cout << 1+!gg;
  }
}