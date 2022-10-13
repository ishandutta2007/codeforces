#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using ll = long long;
const int MX = 2e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> adj[n];
    for(int i=0;i<n-1;i++) {
      int v; cin >> v;
      --v;
      adj[v].push_back(i+1);
      adj[i+1].push_back(v);
    }
    vector<int> a(n);
    a[0] = 0;
    for(int i=1;i<n;i++) cin >> a[i];
    vector<int> d(n);
    vector<bool> vis(n);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    int mx = 0;
    while(!q.empty()) {
      int curr = q.front();
      q.pop();
      vis[curr] = true;
      for(int next : adj[curr]) {
        if(vis[next]) continue;
        d[next] = d[curr] + 1;
        q.push(next);
        mx = max(mx, d[next]);
      }
    }
    vector<pair<int, int>> ord[n];
    for(int i=0;i<n;i++) {
      ord[d[i]].push_back({a[i], i});
    }
    for(int i=0;i<n;i++) {
      sort(ord[i].begin(), ord[i].end());
    }
    vector<ll> dp(n);
    fill(dp.begin(), dp.end(), 0LL);
    for(int currDepth = 0; currDepth < n; currDepth++) {
      vector<int> in;
      for(auto &curr : ord[currDepth]) {
        in.push_back(curr.f);
      }
      for(auto &curr : ord[currDepth]) {
        //no swap
        for(auto &next : adj[curr.s]) {
          if(d[next] < d[curr.s]) continue;
          dp[next] = max(dp[next], dp[curr.s] + max(curr.f - in[0], in.back() - curr.f));
        }
      }
      multiset<ll> less, greater;
      for(auto &curr : ord[currDepth]) {
        greater.insert(dp[curr.s] + curr.f);
      }
      for(auto &curr : ord[currDepth]) {
        //swap
        less.insert(dp[curr.s] - curr.f);
        for(auto &next : adj[curr.s]) {
          if(d[next] < d[curr.s]) continue;
          dp[next] = max(dp[next], *greater.rbegin() - curr.f);
          dp[next] = max(dp[next], *less.rbegin() + curr.f);
        }
        greater.erase(greater.lower_bound(dp[curr.s] + curr.f));
      }
    }
    ll ans = 0LL;
    for(int i=0;i<n;i++) {
      if(d[i] != mx) continue;
      ans = max(ans, dp[i] + max(a[i] - ord[mx][0].f, ord[mx].back().f - a[i]));
    }
    cout << ans << "\n";
  }
}