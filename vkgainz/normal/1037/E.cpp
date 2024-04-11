#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 1e6+5;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> in;
  vector<int> adj[n];
  int outDeg[n];
  memset(outDeg,0,sizeof(outDeg));
  for(int i=0;i<m;i++) {
    int x,y; cin >> x >> y;
    --x, --y;
    in.push_back({x, y});
    adj[x].push_back(y);
    adj[y].push_back(x);
    ++outDeg[x], ++outDeg[y];
  }
  if(k>ceil(2*sqrt(m))) {
    for(int i=0;i<m;i++) {
      cout << 0 << "\n";
    }
    return 0; //chck this
  }
  reverse(in.begin(), in.end());
  queue<int> bad;
  bool rem[n];
  int num = n;
  memset(rem,0,sizeof(rem));
  for(int i=0;i<n;i++) {
    if(outDeg[i]<k) {
      bad.push(i);
      rem[i] = 1;
      --num;
    }
  }
  set<pair<int, int>> edge;
  while(!bad.empty()) {
    int x = bad.front();
    bad.pop();
    for(int next : adj[x]) {
      if(!edge.count({next, x}) && !edge.count({x, next})) {
        --outDeg[next], --outDeg[x];
        edge.insert({x, next});
      }
      if(!rem[next] && outDeg[next]<k) {
          rem[next] = true;
          bad.push(next);
          --num;
      }
    }
  }
  vector<int> ans;
  for(auto &it : in) {
    ans.push_back(num);
    if(edge.count({it.f, it.s}) || edge.count({it.s, it.f}))
      continue;
    --outDeg[it.f], --outDeg[it.s];
    edge.insert({it.f, it.s});
    if(!rem[it.f] &&outDeg[it.f]<k) bad.push(it.f), rem[it.f] = true, --num;
    if(!rem[it.s] && outDeg[it.s]<k) bad.push(it.s), rem[it.s] = true, --num;
    while(!bad.empty()) {
      int x = bad.front();
      bad.pop();
      for(int next : adj[x]) {
        if(!edge.count({next, x}) && !edge.count({x, next})) {
          --outDeg[next], --outDeg[x];
          edge.insert({next, x});
        }
        if(!rem[next] && outDeg[next]<k) {
          rem[next] = true;
          bad.push(next);
          --num;
        }
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for(auto &it : ans) cout << it << "\n";
}