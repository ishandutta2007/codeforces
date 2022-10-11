#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INFLL 1023456789123456789ll

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  
  vector<vector<pair<int, long long> > > adj(n+1);
  for (int i = 0; i < m; i++) {
    int a, b;
    long long w;
    cin >> a >> b >> w;
    adj[a].push_back({b, 2*w});
    adj[b].push_back({a, 2*w});
  }
  for (int i = 1; i <= n; i++) {
    long long w;
    cin >> w;
    adj[0].push_back(make_pair(i, w));
    adj[i].push_back(make_pair(0, w));
  }
  
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > Q;
  vector<long long> dist(n+1, INFLL);
  
  Q.push({0, 0});
  dist[0] = 0;
  while (!Q.empty()) {
    long long my_dist = Q.top().first;
    int a = Q.top().second;
    Q.pop();
    if (my_dist > dist[a]) {
      continue;
    }
    for (auto edge : adj[a]) {
      int b = edge.first;
      long long w = edge.second;
      long long ndist = dist[a] + w;
      if (ndist < dist[b]) {
        dist[b] = ndist;
        Q.push({ndist, b});
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << (i == n ? "\n" : " ");
  }
  return 0;
}