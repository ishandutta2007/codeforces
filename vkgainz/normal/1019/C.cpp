#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e6+5;

int main() {
  int n, m; scanf("%d%d",&n,&m);
  vector<int> adj[n];
  for(int i = 0; i < m; i++) {
    int x, y; scanf("%d%d",&x,&y);
    --x, --y;
    adj[x].push_back(y);
  }
  bool vis[n], reach[n];
  memset(vis, 0, sizeof(vis));
  memset(reach, 0, sizeof(reach));
  vector<int> in;
  for(int i=0;i<n;i++) {
    if(vis[i]) continue;
    in.push_back(i);
    for(int j:adj[i])
      vis[j] = true;
  }
  reverse(in.begin(), in.end());
  vector<int> ans;
  for(int x : in) {
    if(reach[x])
      continue;
    ans.push_back(x);
    for(int k : adj[x])
      reach[k] = true;
  }
  printf("%d\n",ans.size());
  for(auto &a : ans)
    printf("%d\n",a+1);
}