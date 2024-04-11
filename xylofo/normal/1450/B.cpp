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
  ll n,k;
  cin>>n>>k;
  vi x(n), y(n);
  rep(i,0,n) {
    cin>>x[i]>>y[i];
  }
  rep(i,0,n) {
    bool ok = true;
    rep(j,0,n) {
      if(abs(x[i] - x[j]) + abs(y[i]-y[j]) > k)
        ok = false;
    }
    if(ok) {
      cout << 1 << endl;
      return;
    }
  }
  cout << -1 << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}