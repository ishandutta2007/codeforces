#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

void solve(int tc) {
  int n;
  cin>>n;
  vi w(n);
  rep(i,0,n) cin >> w[i];
  vi deg(n);
  rep(i,1,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    ++deg[x];
    ++deg[y];
  }
  ll ans = 0;
  rep(i,0,n) ans += w[i];
  vi idx(n);
  iota(all(idx),0);
  sort(all(idx), [&](int a, int b){return w[a] > w[b];});

  cout << ans << " ";
  rep(i,0,n) {
    rep(j,1,deg[idx[i]]) {
      ans += w[idx[i]];
      cout << ans << " ";
    }
  }
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}