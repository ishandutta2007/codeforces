#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;
vector<int> adj[MX];
bool vis[MX];
int n;
bool cycle;
int in;
void dfs(int curr, int par) {
  vis[curr] = true;
  ++in;
  for(int next : adj[curr]) {
    if(next==par) continue;
    if(vis[next]) cycle = true;
    else
      dfs(next, curr);
  }
}
int main() {
  int t; cin >> t;
  while(t--) {
    int m; cin >> n >> m;
    for(int i=0;i<n;i++)
      adj[i].clear(), vis[i] = false;
    int ans = 0;
    for(int i=0;i<m;i++) {
      int x, y; cin >> x >> y;
      --x, --y;
      if(x==y) {
        vis[x] = true;
        continue;
      }
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for(int i=0;i<n;i++) {
      if(vis[i]) continue;
      cycle = false;
      in = 0;
      dfs(i, -1);
      if(cycle) {
        ans+=in+1;
      }
      else {
        ans+=in-1;
      }
    }
    cout << ans << "\n";
  }
}