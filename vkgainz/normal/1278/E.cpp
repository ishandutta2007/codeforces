#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;
const int MX = 5e5+5;
int st[MX], en[MX];
vector<int> adj[MX];
int numChild[MX], sz[MX], t[MX];
void dfs(int curr, int par) {
  if(par != -1) {
    numChild[curr] = adj[curr].size() - 1; 
  }
  else {
    numChild[curr] = adj[curr].size();
  }
  ++sz[curr];
  for(int next : adj[curr]) {
    if(next == par) continue;
    dfs(next, curr);
    sz[curr] += sz[next];
  }
}
void dfs2(int curr, int par) {
  int x = 0;
  for(int next : adj[curr]) {
    if(next == par) continue;
    st[next] = en[curr] - numChild[curr] + (x++);
    en[next] = st[next] + 2 * (t[curr] - sz[next]) + numChild[next];
    t[curr] -= sz[next];
  }
  for(int next : adj[curr]) {
    if(next == par) continue;
    dfs2(next, curr);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  for(int i=0;i<n-1;i++) {
    int x, y; cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0, -1);
  for(int i=0;i<n;i++) {
    t[i] = sz[i];
  }
  st[0] = 0, en[0] = 1+numChild[0];
  dfs2(0, -1);
  for(int i=0;i<n;i++) {
    cout << st[i] + 1 << " " << en[i] + 1 << "\n";
  }
}