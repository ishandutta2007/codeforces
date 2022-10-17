#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

void solve(int tc) {
  int n;
  string s;
  cin >> n >> s;
  vi v(n);
  rep(i,0,n) v[i] = (s[i] == 'L');

  ll qans = 1e9;

  rep(last1,0,2) rep(last2,0,2) {
    vector<vector<ll>> dp(n, vector<ll>(4,-1));
    function<ll(int,int,int)> f = 
      [&](int pos, int prev, int pprev) -> ll {
        if(pos == n) return 0;

        ll& ans = dp[pos][prev + 2*pprev];
        if(ans != -1) return ans;

        ans = 1e9;
        rep(cur,0,2) {
          if(cur == prev && cur == pprev) continue;
          if(pos == n-2 && cur != last2) continue;
          if(pos == n-1 && cur != last1) continue;
          smin(ans, f(pos+1, cur, prev) + (cur != v[pos]));
        }

        return ans;
      };

    smin(qans, f(0,last1,last2));
  }
  cout << qans << endl;
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}