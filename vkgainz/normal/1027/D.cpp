#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;
vector<int> cycle;
bool vis[MX];
int c[MX], a[MX];
bool found = false;
vector<int> adj[MX], rev[MX];
bool cyc[MX];
void dfs(int x) {
  vis[x] = true;
  if(!found)
    cycle.push_back(x);
  for(int next : adj[x]) {
    if(vis[next]) {
      if(found) continue;
      found = true;
      vector<int> temp;
      for(int i=cycle.size()-1;i>=0;i--) {
        temp.push_back(cycle[i]);
        if(cycle[i]==next)
          break;
      }
      cycle = temp;
    }
    else {
      dfs(next);
    }
  }
}
void dfs2(int x, int p) {
  vis[x] = true;
  for(int next : rev[x]) {
    if(next!=p && !cyc[next]) {
      dfs2(next, x);
    }
  }
}
int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for(int i=0;i<n;i++) {
    cin >> a[i];
    --a[i];
    adj[i].push_back(a[i]);
    rev[a[i]].push_back(i);
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    if(!vis[i]) {
      found = false;
      cycle.clear();
      dfs(i);
      int mn = 10000;
      for(auto &a : cycle) mn = min(mn, c[a]), cyc[a] = true;
      if(!found) mn = 0;
      ans+=mn;
      for(auto &a : cycle)
        dfs2(a, -1);
    }
  }
  cout << ans;
}