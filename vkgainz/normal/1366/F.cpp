#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 1e6+5;
struct line {
  ll m, b;
};
double xIntersect(line x, line y) {
  return (y.b - x.b) * 1.0 / (x.m - y.m);
}
struct cmp {
  bool operator() (const line &a, const line &b) const {
    return a.m < b.m;
  }
};
ll dp[2001][2001]; //given y moves, mmax to get to vertex x
int main() {
  int n, m, q; cin >> n >> m >> q;
  vector<pair<int, int>> adj[n];
  for(int i=0;i<m;i++) {
    int u, v, w; cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for(int i=0;i<n;i++) dp[0][i] = -2e9;
  dp[0][0] = 0;
  ll ans = 0LL, mod = 1e9+7;
  for(int len=1;len<=n-1;len++) {
    ll x = 0;
    for(int i=0;i<n;i++) {
      dp[len][i] = -2000000000;
      for(auto &it : adj[i]) {
        dp[len][i] = max(dp[len][i], dp[len-1][it.f]+it.s);
      }
      x = max(x, dp[len][i]);
    }
    ans+=x;
    ans%=mod;
  }
  int mx[n];
  for(int i=0;i<n;i++) {
    mx[i] = 0;
    for(auto &it : adj[i]) mx[i] = max(mx[i], it.s);
  }
  set<line, cmp> toInsert;
  map<ll, ll> getLines;
  for(int i=0;i<n;i++) {
    for(int len=0;len<=n-1;len++) {
      if(dp[len][i]>=0) {
        line next;
        next.m = mx[i];
        next.b = dp[len][i] - mx[i]*1LL*len;
        if(getLines.find(next.m)==getLines.end())
          getLines[next.m] = next.b;
        else getLines[next.m] = max(getLines[next.m], next.b);
      }
    }
  }
  for(auto &it : getLines) {
    toInsert.insert({it.f, it.s});
  }
  deque<line> in;
  auto it = toInsert.begin();
  while(it!=toInsert.end()) {
    while(in.size() > 1 && xIntersect((*it), in.back()) <= xIntersect(in.back(), in[in.size()-2]))
      in.pop_back();
    in.push_back((*it));
    ++it;
  }
  vector<double> points;
  points.push_back(0);
  for(int i=0;i<in.size()-1;i++) {
    double curr = xIntersect(in[i], in[i+1]);
    points.push_back(curr);
  }
  points.push_back(2000000005);
  int left = n;
  for(int i=0;i<points.size()-1;i++) {
    double right = points[i+1];
    int floor = min((int)right, q);
    if(floor < left) continue;
    //[left, floor] with a slope of in[i]
    ll m = in[i].m, b = in[i].b;
    m%=mod, b%=mod;
    //cout << m << " " << b << " " << left << " " << floor << "\n";
    ans += ((ll)floor+left)*1LL*((ll)floor-left+1)/2%mod*1LL*m%mod;
    ans += b%mod*1LL*((ll)floor-left+1)%mod;
    ans %= mod;
    left = floor + 1;
  }
  if(ans < 0) ans += mod;
  cout << ans << "\n";
  //q >= n-1 guaranteed T_T
}