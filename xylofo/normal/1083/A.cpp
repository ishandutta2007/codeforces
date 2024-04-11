#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<ll> w(n);
  rep(i,0,n) cin >> w[i];
  vector<vector<pii> > g(n);
  rep(i,0,n-1) {
    int a,b,d;
    cin>>a>>b>>d;
    --a, --b;
    g[a].eb(b,d);
    g[b].eb(a,d);
  }
  ll ans = 0;
  function<ll(int,int)> dfs = [&](int x, int p) {
    vector<ll> child_paths(2,0);
    for(pii e:g[x]) if(e.X != p) {
      child_paths.eb(dfs(e.X, x)-e.Y);
    }
    sort(child_paths.rbegin(), child_paths.rend());
    ll cur = child_paths[0] + w[x];
    ans = max(ans, cur + child_paths[1]);
    return cur;
  };
  dfs(0,-1);
  cout << ans << endl;
  return 0;
}