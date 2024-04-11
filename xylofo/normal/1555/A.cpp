#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

vector<ll> dp(1000,1e18);
void solve(int tc) {
  debug()
  ll n;
  cin>>n;
  ll ans = 1e18;

  for(auto [a,b] : vector<pii>{{6,15},{8,20},{10,25}}) {
    ll q = max<ll>(0, (n-sz(dp))/a+1);
    debug(n-q*a, dp[n-q*a], q*b);
    smin(ans, dp[n-q*a] + q*b);
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  dp[0] = 0;
  rep(i,0,sz(dp)) {
    for(int j = max(i-6,0); j < i; ++j) smin(dp[i], dp[j]+15);
    for(int j = max(i-8,0); j < i; ++j) smin(dp[i], dp[j]+20);
    for(int j = max(i-10,0); j < i; ++j) smin(dp[i], dp[j]+25);
  }

  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}