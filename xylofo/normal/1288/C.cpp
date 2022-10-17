#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll md = 1e9 + 7;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vi dp(n+1);
  dp[1] = 1;
  rep(i,0,2*m+1) {
    vi ndp(n+1);
    rep(x,1,n+1) ndp[x] = (ndp[x-1] + dp[x]) % md;
    swap(ndp, dp);
  }
  cout << dp[n] << endl;
}