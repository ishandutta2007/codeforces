#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  ll sum = 0;
  rep(i,0,n) sum += i;

  auto First = [&](){
    cout << "First" << endl;
    rep(i,0,2*n)
      cout << i%n+1 << " ";
    cout << endl;
  };

  auto Second = [&](){
    cout << "Second" << endl;
    vector<vi> g(n);
    vector<vi> rg(n);
    vector<vi> pairs(n);
    rep(i,1,2*n+1) {
      int p;
      cin>>p;
      --p;
      g[p].emplace_back(i%n);
      rg[i%n].emplace_back(p);
      pairs[p].emplace_back(i);
    }

    vi vis(n);
    vi btoa(n,-1);
    rep(i,0,n) if(!vis[i]) {
      int x = i;
      int y = g[x][0];
      do {
        vis[x] = 1;
        btoa[y] = x;
        if(rg[y][0] == x) swap(rg[y][0], rg[y][1]);
        assert(rg[y][1] == x);
        x = rg[y][0];
        if(g[x][0] == y) swap(g[x][0], g[x][1]);
        assert(g[x][1] == y);
        y = g[x][0];
      } while(x != i);
    }

    vi ans1, ans2;
    ll sm1 = 0, sm2 = 0;
    rep(i,0,n) {
      int p = btoa[i];
      if(pairs[p][0]%n != i) swap(pairs[p][0], pairs[p][1]);
      assert(pairs[p][0]%n == i);
      ans1.push_back(pairs[p][0]);
      ans2.push_back(pairs[p][1]);
      sm1 += pairs[p][0];
      sm2 += pairs[p][1];
    }
    if(sm1 % (2*n) != 0) swap(sm1, sm2), swap(ans1, ans2);
    assert(sm1 % (2*n) == 0);
    rep(i,0,n) cout << ans1[i] << " ";
    cout << endl;
  };

  if(sum % n == 0) Second();
  else First();

  int ok;
  cin>>ok;
  assert(ok == 0);
}