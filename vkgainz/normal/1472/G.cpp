#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
vector<int> idx;
vector<int> dist;
bool cmp(const int &x, const int &y) {
  return dist[x] < dist[y];
}
int main() {
    int t; cin >> t;
    while(t--) {
      int n, m; cin >> n >> m;
      vector<int> adj[n];
      for(int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
      }
      dist.clear();
      dist.resize(n);
      for(int i=0;i<n;i++) dist[i] = 100000000;
      queue<int> q;
      q.push(0);
      dist[0] = 0;
      while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int next : adj[x]) {
          if(dist[x] + 1 < dist[next]) {
            dist[next] = dist[x] + 1;
            q.push(next);
          }
        }
      }
      idx.clear();
      for(int i=0;i<n;i++) idx.push_back(i);
      sort(idx.begin(), idx.end(), cmp);
      vector<int> ans(n);
      while(!idx.empty()) {
        int x = idx.back();
        ans[x] = dist[x];
        idx.pop_back();
        for(int next : adj[x]) {
          if(dist[next] > dist[x]) {
            ans[x] = min(ans[next], ans[x]);
          }
          else {
            ans[x] = min(ans[x], dist[next]);
          }
        }
      }
      for(int i=0;i<n;i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
}