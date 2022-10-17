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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  m += 100;
  vi cnt(m);
  rep(i,0,n) {
    int x;
    cin>>x;
    ++cnt[x+50];
  }

  int ans = 0;
  rep(x,0,m) {
    while(cnt[x]-3 >= 6) {
      ++ans;
      cnt[x] -= 3;
    }
  }

  vector<vi> dp(9, vi(9,-1e9)); // dp[used(i-2)][used(i-1)] = can form when used
  dp[0][0] = 0;
  for(int i = m; i--;) {
    assert(cnt[i] < 9);

    vector<vi> ndp(9, vi(9,-1e9));
    for(int a = cnt[i]; a >= 0; --a) rep(b,0,9) {
      if(a+3 <= cnt[i]) smax(ndp[a][b], ndp[a+3][b]+1);
      if(a+1 <= cnt[i]) smax(ndp[a][b], ndp[a+1][b]);
      rep(k,0,cnt[i]-a+1) if(b+k < 9) smax(ndp[a][b], dp[b+k][k]+k);
    }
    swap(dp, ndp);
  }

  // f(i,a,b) = max { // used a i, b (i+1) 
  //   -inf if a > cnt[i],
  //   f(i,a+3,b)
  //   f(i+1,b+k,k) if a+k <= cnt[i]
  // }
  cout << ans + dp[0][0] << endl;
}