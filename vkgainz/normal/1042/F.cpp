#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 1e6+5;
vector<int> adj[MX];
int k;
pair<int, int> dfs(int curr, int par) {
  pair<int, int> ans = {0, 0};
  vector<int> in;
  for(int next : adj[curr]) {
    if(next==par) continue;
    pair<int, int> p = dfs(next, curr);
    //cout << next << " " << p.first << " " << p.second << "\n";
    ans.f+=p.f;
    in.push_back(p.s+1);
  }
  if(in.empty()) {
    ans.s = 0;
    if(curr==0)
      ++ans.f;
    return ans;
  }
  sort(in.begin(), in.end());
  //do some stuff!
  int r = in.size()-1;
  while(r>0 && in[r]+in[r-1]>k) {
    --r, ++ans.f;
  }
  ans.s = in[r];//check this
  if(curr==0)
    ++ans.f;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n >> k;
  for(int i=0;i<n-1;i++) {
    int x, y; cin >>x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  pair<int, int> ans;
  for(int i=0;i<n;i++) {
    if(adj[i].size()>1) {
      ans = dfs(i, -1);
      break;
    }
  }
  cout << ans.f << "\n";
}