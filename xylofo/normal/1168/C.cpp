#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin>>n>>q;
  vi v(n), nxt(20,n);
  rep(i,0,n) cin>>v[i];
  vector<vi> reach(20,vi(n+1,n));
  for(int i = n; i-->0;) {
    rep(bit,0,20) rep(k,0,20) if(v[i]>>k&1)
      reach[bit][i] = min(reach[bit][i], reach[bit][nxt[k]]);
    rep(bit,0,20) if(v[i]>>bit&1) nxt[bit] = reach[bit][i] = i;
  }
  rep(i,0,q) {
    int x, y;
    cin>>x>>y;
    --x,--y;
    string ans = "Fou\n";
    rep(bit,0,20) if(v[y]>>bit&1) {
      if(reach[bit][x] <= y) ans = "Shi\n";
    }
    cout << ans;
  }
}