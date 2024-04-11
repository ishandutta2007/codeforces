#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;
  vector<vector<ll>> dp(n, vector<ll>(m,-1e9));
  function<ll(int,int)> solve = [&](int i, int j) -> ll {
    if(i == n || j == m) return 0;
    ll& ans = dp[i][j];
    if(ans != -1e9) return ans;

    ans = 0;
    if(a[i] == b[j]) smax(ans, solve(i+1,j+1)+2);
    smax(ans, solve(i+1,j)-1);
    smax(ans, solve(i,j+1)-1);
    return ans;
  };

  ll ans = 0;
  rep(i,0,n+1) rep(j,0,m+1)
    smax(ans, solve(i,j));

  cout << ans << endl;

}