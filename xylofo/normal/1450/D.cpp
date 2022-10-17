#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  int n;
  cin>>n;
  vi v(n);
  rep(i,0,n) {
    cin>>v[i];
    --v[i];
  }



  vector<vi> pos(n+10);
  rep(i,0,n) {
    pos[v[i]].emplace_back(i);
  }

  vi ans(n);
  ans[0] = 1;
  rep(i,0,n) if(sz(pos[i]) == 0) ans[0] = 0;


  function<void(int,int,int)> rec = [&](int l, int r, int x) {
    if(sz(pos[x]) == 0) return;

    ans[r-l-1] = 1;
    if(sz(pos[x]) >= 2) return;
    assert(sz(pos[x]) == 1);
    if(pos[x][0] == l) rec(l+1,r,x+1);
    if(pos[x][0] == r-1) rec(l,r-1,x+1);
  };
  rec(0,n,0);

  rep(i,0,n) cout << ans[i];
  cout << "\n";

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}