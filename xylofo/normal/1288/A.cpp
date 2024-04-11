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
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  ll t, n, d;
  cin >> t;
  rep(i,0,t) {
    cin >> n >> d;
    ll a = max<ll>(0, sqrt(d) - 100);
    ll b = min<ll>(n, sqrt(d) + 100);
    bool ok = false;
    rep(x,a,b) if(x + (d+x)/(x+1) <= n)
      ok = true;
    cout << vector{"NO","YES"}[ok] << endl;
  }
}