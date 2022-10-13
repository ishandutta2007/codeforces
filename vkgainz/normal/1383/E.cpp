#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)
ll dp[1000002];
ll f[1000002];
ll g[1000002];
int nxt[1000002];
int main() {
  string s; cin >> s;
  vector<array<int, 2>> in;
  bool st = 0;
  if(s[0] == '1') st = 1;
  int curr = 0;
  int prod = 1;
  while(s.size() && s.back() == '0') s.pop_back(), ++prod;
  if(s.empty()) {
    cout << prod - 1 << "\n";
    return 0;
  }
  for(int i = 0; i < s.length(); i++) {
    if(s[i] - '0' == st) curr++;
    else {
      in.push_back(array<int, 2>());
      in.back()[0] = curr;
      in.back()[1] = st;
      st = 1 - st;
      curr = 1;
    }
  }
  in.push_back(array<int, 2>());
  in.back()[0] = curr;
  in.back()[1] = st;
  ll MOD = 1e9 + 7;
  vector<int> stack;
  memset(nxt, -1, sizeof(nxt));
  for(int i = in.size() - 1; i >= 0; i--) {
    int x = in[i][0], y = in[i][1];
    if(y == 1) {
      dp[i] = x * 1LL * g[i + 1] + dp[i + 2] + x; //calculate properly
      dp[i] %= MOD;
    }
    else {
      dp[i] = x * 1LL * dp[i + 1];
      f[i] = dp[i + 1];
      if(i + 1 == in.size()) dp[i] = x;
      if(i == 0 && in.size() >= 2) dp[i] += dp[i + 1];
      dp[i] %= MOD;
      f[i] %= MOD;
      while(stack.size() && in[stack.back()][0] <= x)
        stack.pop_back();
      if(stack.size())
        nxt[i] = stack.back();
      if(nxt[i] != -1)
        g[i] = x*1LL*(f[i] - f[nxt[i]]) + g[nxt[i]];
      else
        g[i] = x*1LL*f[i];
      g[i] %= MOD;
      stack.push_back(i);
    }
  }
  ll ans = dp[0]*1LL*prod % MOD;
  if(ans < 0) ans += MOD;
  cout << ans;
}