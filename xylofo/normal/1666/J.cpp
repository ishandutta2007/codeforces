#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

vector<ll> operator+(vector<ll> a, vector<ll> b) {
  int n = sz(a);
  vector<ll> res(n);
  rep(i,0,n) {
    res[i] = a[i] + b[i];
  }
  return res;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int n; cin >> n;
  vector<vi> c(n, vi(n));
  rep(i,0,n) rep(j,0,n) cin >> c[i][j];

  vector<vector<ll>> prefPrefSum(n+1, vector<ll>(n+1));
  rep(i,0,n) {
    rep(j,0,n) {
      prefPrefSum[i+1][j+1] = prefPrefSum[i+1][j] + c[i][j];
    }
    prefPrefSum[i+1] = prefPrefSum[i] + prefPrefSum[i+1];
  }
  //rep(i,0,n+1) {
  //  rep(j,0,n+1) {
  //    cerr << prefPrefSum[i][j] << " ";
  //  }
  //  cerr << endl;
  //}
  auto getArea = [&](int rowLo, int rowHi, int colLo, int colHi) {
    ll res = prefPrefSum[rowHi][colHi] + prefPrefSum[rowLo][colLo];
    res -= prefPrefSum[rowLo][colHi] + prefPrefSum[rowHi][colLo];
    return res;
  };

  vector<vector<vector<ll>>> savedMoveCosts(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, -1)));
  auto moveCost = [&](int a, int i, int b) {
    ll& res = savedMoveCosts[a][i][b];
    if (res == -1) {
      /* we want area where
      [a,i) talks to [i+1, b)
      i talks to [a, b)
      [0,a) or [b,n) talks to [a,b) excluding i
      */
      res = 2*getArea(a,i, i+1,b) + getArea(i,i+1, a,b);
      res += getArea(0,a, a,b) + getArea(b,n, a,b);
      res -= getArea(0,a, i,i+1) + getArea(b,n, i,i+1);
    }
    return res;
  };

  //rep(a,0,n) rep(b,a+1,n+1) rep(i,a,b) {
  //  cerr << a+1 << " " << i+1 << " " << b+1 << ": " << moveCost(a,i,b) << endl;
  //}

  vector<vector<ll>> dpTable(n+1, vector<ll>(n+1, -1));
  function<ll(int,int)> dp = [&](int a, int b) -> ll {
    if (a == b) return 0;
    ll& res = dpTable[a][b];
    if (res == -1) {
      res = 1ll<<60;
      rep(i,a,b) {
        ll tempRes = moveCost(a, i, b) + dp(a, i) + dp(i+1, b);
        res = min(res, tempRes);
      }
    }
    return res;
  };

  vi parent(n, -1);
  function<void(int,int)> setParent = [&](int a, int b) {
    if (a == b) return;
    rep(i,a,b) {
      ll tempRes = moveCost(a,i,b) + dp(a,i) + dp(i+1,b);
      if (tempRes == dpTable[a][b]) {
        rep(x,a,b) if (x != i) {
          parent[x] = i;
        }
        setParent(a,i);
        setParent(i+1,b);
        break;
      }
    }
  };

  cerr << dp(0, n) << endl;
  setParent(0, n);
  trav(elem, parent) cout << elem+1 << " ";
  cout << endl;
}