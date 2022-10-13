#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e5 + 5;
struct node {
  int x, y, idx;
};
bool cmpx(node &x, node &y) {
  return x.x < y.x;
}
bool cmpy(node &x, node &y) {
  return x.y < y.y;
}
vector<pair<int, int>> adj[MX];
int main() {
  int n; cin >> n;
  int m; cin >> m;
  vector<node> in;
  int sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  for(int i=0;i<m;i++) {
    in.push_back(node());
    cin >> in.back().x >> in.back().y;
    in.back().idx = i;
    int w = abs(sx-in.back().x) + abs(sy-in.back().y), w2 = min(abs(sx-in.back().x), abs(sy-in.back().y));
    adj[i].push_back({w, m});
    adj[m].push_back({w2, i});
    w = abs(fx-in.back().x) + abs(fy-in.back().y), w2 = min(abs(fx-in.back().x), abs(fy-in.back().y));
    adj[i].push_back({w, m+1});
    adj[m+1].push_back({w2, i});
  }
  int w = abs(sx-fx)+abs(sy-fy);
  adj[m].push_back({w, m+1});
  adj[m+1].push_back({w, m});
  sort(in.begin(), in.end(), cmpx);
  for(int i=1;i<m;i++) {
    adj[in[i].idx].push_back({in[i].x - in[i-1].x, in[i-1].idx});
    adj[in[i-1].idx].push_back({in[i].x - in[i-1].x, in[i].idx});
  }
  sort(in.begin(), in.end(), cmpy);
  for(int i=1;i<m;i++) {
    adj[in[i].idx].push_back({in[i].y - in[i-1].y, in[i-1].idx});
    adj[in[i-1].idx].push_back({in[i].y - in[i-1].y, in[i].idx});
  }
  vector<ll> dist(m+2, 1e15);
  set<pair<ll, int>> pq;
  dist[m] = 0LL;
  pq.insert({0, m});
  while(!pq.empty()) {
    auto curr = *pq.begin();
    pq.erase(pq.begin());
    for(auto &next : adj[curr.s]) {
      if(dist[curr.s] + next.f < dist[next.s]) {
        dist[next.s] = dist[curr.s] + next.f;
        pq.insert({dist[next.s], next.s});
      }
    }
  }
  cout << dist[m+1] << "\n";
}