#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int inf = 1e9 + 12345;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back({v, c});
  }
  auto solve = [&](int s) {
    vector<int> dist(n, inf), mn_cost(n);
    vector<bool> used(n, false);
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
      pair<int, int> best = {inf, inf};
      for (int j = 0; j < n; j++) {
        if (!used[j]) {
          best = min(best, {dist[j], j});
        }
      }
      used[best.second] = true;
      fill(mn_cost.begin(), mn_cost.end(), inf);
      for (auto& edge : g[best.second]) {
        mn_cost[(edge.first + best.first) % n] = min(mn_cost[(edge.first + best.first) % n], edge.second);
      }
      int current_cost = inf;
      for (int iter = 0; iter < 2; iter++) {
        for (int j = 0; j < n; j++) {
          current_cost = min(current_cost + 1, mn_cost[j]);
          if (current_cost < inf) {
            dist[j] = min(dist[j], best.first + current_cost);
          }
        }
      }
    }
    return dist;
  };
  vector<vector<int>> answer(n);
  for (int i = 0; i < n; i++) {
    answer[i] = solve(i);
  }
  for (auto& row : answer) {
    for (auto& cell : row) {
      cout << cell << ' ';
    }
    cout << '\n';
  }
}