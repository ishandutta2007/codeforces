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
  cin >> n;
  vector<vector<ll>> a(n,vector<ll>(n,0));
  rep(x,0,n) rep(y,0,n) {
    ll k = (x+y);
    if(x % 2) a[x][y] = (1LL << k);
  }
  rep(i,0,n) {
    rep(j,0,n) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }


  int q;
  cin>>q;
  rep(i,0,q) {
    ll k;
    cin>>k;
    int x = 0, y = 0;
    auto nxt = [&](int x, int y) -> int {
      if(x >= n || y >= n) return false;
      ll s = (1LL << (x+y+1LL));
      return (a[x][y] % s == k % s);
    };
    while(x != n-1 || y != n-1) {
      cout << (x+1) << " "<< (y+1) << "\n";
      assert(nxt(x+1, y) + nxt(x, y+1) == 1);
      if(nxt(x+1, y)) x++;
      else y++;
      k -= a[x][y];
    }
    assert(k == 0);
    cout << n << " " << n << endl;
  }
}